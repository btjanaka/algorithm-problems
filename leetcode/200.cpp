// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 200
// Title: Number of Islands
// Link: https://leetcode.com/problems/number-of-islands
// Idea: Count connected components with your favorite graph traversal
// algorithm.
// Difficulty: medium
// Tags: graph, connected-components
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int nrows = grid.size();
    if (grid.size() == 0) return 0;
    int ncols = grid[0].size();
    vector<vector<bool>> visited(nrows, vector<bool>(ncols, false));
    int count = 0;
    for (int i = 0; i < nrows; ++i) {
      for (int j = 0; j < ncols; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          ++count;
          dfs(i, j, visited, grid);
        }
      }
    }
    return count;
  }

  void dfs(int row, int col, vector<vector<bool>>& visited,
           const vector<vector<char>>& grid) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
        grid[row][col] != '1' || visited[row][col])
      return;

    visited[row][col] = true;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
      int r2 = row + dr[i];
      int c2 = col + dc[i];
      dfs(r2, c2, visited, grid);
    }
  }
};
