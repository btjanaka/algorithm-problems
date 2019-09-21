// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 37
// Title: Sudoku Solver
// Link: https://leetcode.com/problems/sudoku-solver/
// Idea: Very similar to n-queens (see comment for solve function).
// Difficulty: medium
// Tags: implementation, recursion, n-queens
class Solution {
 public:
  // Cells are numbered
  // 0 1 2
  // 3 4 5
  // 6 7 8
  inline int cell_of(int r, int c) {
    int cell_r = r / 3;
    int cell_c = c / 3;
    return cell_r * 3 + cell_c;
  }

  // Treat similar to n-queens problem - keep track of state and use it to tell
  // what moves we can do. The runtime of this is technically T(n) = n * T(n -
  // 1) + O(n) where n is the number of squares in the board (81) - thus it's
  // O(n!) but there's plenty of optimizations that kill the runtime.
  //
  // In the rows_with, cols_with, cells_with vectors, element i is a bitset
  // telling which row, coll, cell has i in it.
  bool solve(int row, int col, vector<vector<int>>& board,
             vector<int>& rows_with, vector<int>& cols_with,
             vector<int>& cells_with) {
    if (row == 9) return true;  // Base case - reached end

    // Next coords
    int next_row, next_col;
    if (col == 8) {
      next_row = row + 1;
      next_col = 0;
    } else {
      next_row = row;
      next_col = col + 1;
    }

    // If the cell is already set, return the solution to the next cell.
    if (board[row][col] != 0)
      return solve(next_row, next_col, board, rows_with, cols_with, cells_with);

    // Otherwise, try all possible values of n
    for (int n = 1; n <= 9; ++n) {
      if (!(rows_with[n] & (1 << row)) && !(cols_with[n] & (1 << col)) &&
          !(cells_with[n] & (1 << cell_of(row, col)))) {
        int prev_rows_with = rows_with[n];
        int prev_cols_with = cols_with[n];
        int prev_cells_with = cells_with[n];

        rows_with[n] |= 1 << row;
        cols_with[n] |= 1 << col;
        cells_with[n] |= 1 << cell_of(row, col);
        board[row][col] = n;
        bool solved =
            solve(next_row, next_col, board, rows_with, cols_with, cells_with);
        if (solved) {
          return true;
        } else {
          rows_with[n] = prev_rows_with;
          cols_with[n] = prev_cols_with;
          cells_with[n] = prev_cells_with;
          board[row][col] = 0;
        }
      }
    }
    return false;  // Nothing worked for this combo.
  }

  void solveSudoku(vector<vector<char>>& text_board) {
    vector<vector<int>> board(9, vector<int>(9, 0));
    vector<int> rows_with(10);
    vector<int> cols_with(10);
    vector<int> cells_with(10);
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (text_board[r][c] == '.') {
          board[r][c] = 0;
          continue;
        }
        int n = text_board[r][c] - '0';
        rows_with[n] |= 1 << r;
        cols_with[n] |= 1 << c;
        cells_with[n] |= 1 << cell_of(r, c);
        board[r][c] = n;
      }
    }

    solve(0, 0, board, rows_with, cols_with, cells_with);

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        text_board[i][j] = board[i][j] + '0';
      }
    }
  }
};
