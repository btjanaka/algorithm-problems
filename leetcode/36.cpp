// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 36
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 9; ++i) {
      int seen = 0;
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.' && seen & (1 << board[i][j] - '1')) {
          return false;
        }
        seen |= 1 << board[i][j] - '1';
      }
    }

    // Check columns
    for (int i = 0; i < 9; ++i) {
      int seen = 0;
      for (int j = 0; j < 9; ++j) {
        if (board[j][i] != '.' && seen & (1 << board[j][i] - '1')) {
          return false;
        }
        seen |= 1 << board[j][i] - '1';
      }
    }

    // Check squares
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        int seen = 0;
        for (int r = 0; r < 3; ++r) {
          for (int c = 0; c < 3; ++c) {
            if (board[i + r][j + c] != '.' &&
                seen & (1 << board[i + r][j + c] - '1')) {
              return false;
            }
            seen |= 1 << board[i + r][j + c] - '1';
          }
        }
      }
    }

    return true;
  }
};
