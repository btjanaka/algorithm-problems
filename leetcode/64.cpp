// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 64
// Title: Minimum Path Sum
// Link: https://leetcode.com/problems/minimum-path-sum/description/
// Idea:
// Difficulty:
// Tags:
class Solution {
 public:
  // In each cell, the best path is min(cost of cell to left, cost of cell
  // above) + current cell value.
  int minPathSum(vector<vector<int>>& grid) {
    // We add 1 to each dim to avoid having to check the bounds during the
    // computation. However, the initial values need to be done carefully --
    // only the external cells that lead into cost[1][1] should be 0.
    vector<vector<int>> cost(grid.size() + 1,
                             vector<int>(grid[0].size() + 1, INT_MAX));
    cost[0][1] = 0;
    cost[1][0] = 0;
    for (int r = 0; r < grid.size(); ++r) {
      for (int c = 0; c < grid[0].size(); ++c) {
        cost[r + 1][c + 1] = min(cost[r][c + 1], cost[r + 1][c]) + grid[r][c];
      }
    }
    return cost.back().back();
  }
};
