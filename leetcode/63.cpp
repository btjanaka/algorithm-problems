// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 63
// Title: Unique Paths II
// Link: https://leetcode.com/problems/unique-paths-ii
// Idea: See Unique Paths (#62). This problem is very similar, except that we
// mark obstacle squares as having 0 paths to the goal.
// Difficulty: medium
// Tags: dynamic-programming
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int grid[m][n];
    grid[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (obstacleGrid[i][j] == 1) {
          grid[i][j] = 0;
        } else {
          if (!(i == m - 1 && j == n - 1)) {
            grid[i][j] = 0;
            if (i < m - 1) {
              grid[i][j] += grid[i + 1][j];
            }
            if (j < n - 1) {
              grid[i][j] += grid[i][j + 1];
            }
          }
        }
      }
    }
    return grid[0][0];
  }
};
