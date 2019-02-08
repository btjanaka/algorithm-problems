// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 51
class Solution {
 public:
  // Parameters:
  // - col: The current column to investigate
  // - rows: An array where the i'th entry tells the
  //         row of the queen in column i
  // - rw: a bitset telling which rows are occupied
  // - ld: a bitset telling which left diagonals
  //       (from top left to bottom right) are occupied
  // - rd: a bitset telling which right diagonals
  //       (from top right to bottom left) are occupied
  // - res: the list of solution boards
  // - n: the size of the board
  void backtrack(int col, int rows[], long long rw, long long ld, long long rd,
                 vector<vector<string>>& res, int n) {
    // Terminating case - filled up board
    if (col == n) {
      // Add the result to the list of results
      add_empty_board(res, n);
      int board_index = res.size() - 1;
      for (int i = 0; i < n; ++i) {
        res[board_index][rows[i]][i] = 'Q';
      }
      return;
    }

    for (int i = 0; i < n; ++i) {
      long long next = 1L << i;
      // Check if row, left diagonal, and right diagonal is clear
      if (!(next & rw) && !(next & ld) && !(next & rd)) {
        rows[col] = i;
        backtrack(col + 1, rows, rw | next, (ld | next) << 1, (rd | next) >> 1,
                  res, n);
      }
    }
  }

  void add_empty_board(vector<vector<string>>& boards, int n) {
    boards.push_back(vector<string>(n, string(n, '.')));
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    int rows[n];
    memset(rows, 0, sizeof(rows));
    backtrack(0, rows, 0, 0, 0, res, n);
    return res;
  }
};
