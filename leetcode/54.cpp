// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 54
// Title: Spiral Matrix
// Link: https://leetcode.com/problems/spiral-matrix/
// Idea: Use a separate function to continuously determine what coordinates are
// "next" - at first we try to go as far right as possible, then down, left, and
// up.
// Difficulty: medium
// Tags: implementation, arrays
class Solution {
 public:
  // right, down, left, up
  static constexpr int dr[4] = {0, 1, 0, -1};
  static constexpr int dc[4] = {1, 0, -1, 0};

  // Determines the next (row, column) coordinates to go to. |visited| keeps us
  // from encountering the same coordinates again.
  inline pair<int, int> next(int r, int c, int* dir, int m, int n,
                             vector<vector<bool>>& visited) {
    int r2 = r + dr[*dir], c2 = c + dc[*dir];  // Try the current direction.
    if (r2 >= m || r2 < 0 || c2 >= n || c2 < 0 || visited[r2][c2]) {
      // If the current direction fails, go to the next direction.
      *dir = (*dir + 1) % 4;
      r2 = r + dr[*dir];
      c2 = c + dc[*dir];
    }
    return {r2, c2};
  }

  inline vector<int> spiralOrder(vector<vector<int>>& matrix) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m = matrix.size();
    if (m == 0) return {};
    int n = matrix[0].size();
    if (n == 0) return {};

    vector<int> spiral;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int dir = 0;
    int r = 0, c = 0;
    int total = m * n;
    for (int i = 0; i < total; ++i) {
      spiral.push_back(matrix[r][c]);
      visited[r][c] = true;
      if (i < total - 1) tie(r, c) = next(r, c, &dir, m, n, visited);
    }

    return spiral;
  }
};
