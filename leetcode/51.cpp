// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 51
// Title: N-Queens
// Link: https://leetcode.com/problems/n-queens/
// Idea: The first solution is more optimized; see the second one for a deeper
// explanation.
// Difficulty: medium
// Tags: recursion
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

// Idea: N-Queens is a classic problem involving recursive backtracking. In the
// problem, we treat the board as a series of columns. Our job is then to
// recursively place 1 queen in each column. As we recur through the columns, we
// keep track of several parameters (see the backtrack function) that give us
// information such as what squares we can still place queens on and what queens
// we have placed so far. Once we placed n queens, we record those solutions in
// a result vector.
class Solution {
 public:
  // Adds an empty board to the given vector of boards.
  void add_empty_board(vector<vector<string>>& boards, int n) {
    boards.push_back(vector<string>(n, string(n, '.')));
  }

  // Recurs through the columns of the board to find the solution. The board is
  // seen with coordinates like below.
  //
  //  3 . . Q .
  //  2 Q . . .
  //  1 . . . Q
  //  0 . Q . .
  //    0 1 2 3
  //
  // Parameters:
  // - col: The current column to investigate.
  // - queen_rows: A list recording the positions of the queens we have placed
  //   so far. Item |i| tells the what row the queen in column |i| is located
  //   in.
  // - occupied_rows: A bitset telling which rows are currently being attacked
  //   by previous queens.
  // - occupied_left_diagonals: A bitset telling which left diagonals (going
  //   from bottom left to top right) are being attacked by previous queens.
  // - occupied_right_diagonals: A bitset telling which right diagonals (going
  //   from top left to bottom right) are being attacked by previous queens.
  // - res: The list of solution boards.
  // - n: The size of the board.
  void backtrack(int current_col, vector<int>& queen_rows,
                 long long occupied_rows, long long occupied_left_diagonals,
                 long long occupied_right_diagonals,
                 vector<vector<string>>& res, int n) {
    // Base case - we filled up the board if the current column is equal to the
    // number of columns in the board (since we are using 0-based indexing).
    if (current_col == n) {
      // Add the result to the list of results. We add an empty board and fill
      // in queen positions.
      add_empty_board(res, n);
      for (int i = 0; i < n; ++i) res.back()[queen_rows[i]][i] = 'Q';
      return;
    }

    for (int row = 0; row < n; ++row) {
      // A bit set representing the potential queen position.
      // The bit set looks something like this:
      //  0001000
      //     ^
      //     queen position
      // Then the occpuied_* bitsets could look something like this:
      //  1010100
      // Depending on what the bitset represents, we manipulate it differently
      // when we go to the next column. See
      // https://www.hackerearth.com/practice/notes/bit-manipulation/ for more
      // on bitsets.
      long long queen_pos_bitset = 1L << row;
      // Check if row, left diagonal, and right diagonal are clear.
      if (!(queen_pos_bitset & occupied_rows) &&
          !(queen_pos_bitset & occupied_left_diagonals) &&
          !(queen_pos_bitset & occupied_right_diagonals)) {
        queen_rows[current_col] = row;
        // The next value of occupied_rows is determined by turning on the bit
        // corresponding to this queen's row by OR'ing with the bitset.
        // occupied_left_diagonals is OR'ed with the row and then shifted left
        // to represent the occupancy being moved up one row. The same goes for
        // occupied_right_diagonals but in the opposite direction.
        backtrack(current_col + 1, queen_rows, occupied_rows | queen_pos_bitset,
                  (occupied_left_diagonals | queen_pos_bitset) << 1,
                  (occupied_right_diagonals | queen_pos_bitset) >> 1, res, n);
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> queen_rows(n);  // Create this here to avoid copies.
    backtrack(0, queen_rows, 0, 0, 0, res, n);
    return res;
  }
};
