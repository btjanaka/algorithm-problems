// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 120
// Title: Triangle
// Link: https://leetcode.com/problems/triangle/description/
// Idea: Dynamic programming -- at each index, you check the minimum path from
// the two cells on the previous row that could have led to it.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> row;
    row.push_back(triangle[0][0]);

    for (int i = 1; i < triangle.size(); ++i) {
      vector<int> row2;
      for (int j = 0; j < i + 1; ++j) {
        row2.push_back(
            min((j == 0) ? INT_MAX : row[j - 1], (j >= i) ? INT_MAX : row[j]) +
            triangle[i][j]);
      }
      row = row2;
    }

    int min_path = INT_MAX;
    for (int x : row) min_path = min(x, min_path);

    return min_path;
  }
};
