// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 118
// Title: Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
// Idea: Implementation.
// Difficulty: Easy
// Tags:
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> rows;
    for (int i = 1; i <= numRows; ++i) {
      vector<int> row;
      for (int j = 0; j < i; ++j) {
        if (j == 0 || j == i - 1) {
          row.push_back(1);
        } else {
          row.push_back(rows.back()[j - 1] + rows.back()[j]);
        }
      }
      rows.push_back(row);
    }
    return rows;
  }
};
