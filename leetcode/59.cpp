// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 59
// Title: Spiral Matrix II
// Link: https://leetcode.com/problems/spiral-matrix-ii/description/
// Idea:
// Difficulty:
// Tags:
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    int r = 0, c = 0;
    int direction = 0;  // 0 = right, 1 = down, 2 = left, 3 = up
    for (int k = 1; k <= n * n; ++k) {
      m[r][c] = k;

      switch (direction) {
        // Move right.
        case 0:
          if (c < n - 1 && m[r][c + 1] == 0) {
            ++c;
          } else {
            direction = 1;
            ++r;
          }
          break;
        // Move down.
        case 1:
          if (r < n - 1 && m[r + 1][c] == 0) {
            ++r;
          } else {
            direction = 2;
            --c;
          }
          break;
        // Move left.
        case 2:
          if (c > 0 && m[r][c - 1] == 0) {
            --c;
          } else {
            direction = 3;
            --r;
          }
          break;
        // Move up.
        case 3:
          if (r > 0 && m[r - 1][c] == 0) {
            --r;
          } else {
            direction = 0;
            ++c;
          }
          break;
      }
    }
    return m;
  }
};
