// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 73
// Title: Set Matrix Zeros
// Link: https://leetcode.com/problems/set-matrix-zeroes/
// Idea: Use column zero and row zero as flags - they indicate which rows and
// columns should have zeros.
// Difficulty:
// Tags:
class Solution {
 public:
  void setZeroes(vector<vector<int>>& m) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Size - careful for edge cases.
    int rows = m.size();
    if (rows == 0) return;
    int cols = m[0].size();
    if (cols == 0) return;

    // Edge case - since row and column 0 are the flag locations too.
    bool in_row_zero = false;
    bool in_col_zero = false;

    // Flag all rows and columns that should be zero.
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (m[r][c] == 0) {
          m[r][0] = 0;
          m[0][c] = 0;
          in_row_zero |= r == 0;
          in_col_zero |= c == 0;
        }
      }
    }

    // Set all rows and columns except for row and column 0.
    for (int r = 1; r < rows; ++r) {
      for (int c = 1; c < cols; ++c) {
        if (m[r][0] == 0 || m[0][c] == 0) {
          m[r][c] = 0;
        }
      }
    }

    // Account for row and column 0.
    if (in_row_zero)
      for (int c = 0; c < cols; ++c) m[0][c] = 0;
    if (in_col_zero)
      for (int r = 0; r < rows; ++r) m[r][0] = 0;
  }
};
