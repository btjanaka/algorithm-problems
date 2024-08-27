// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 119
// Title: Pascal's Triangle II
// Link: https://leetcode.com/problems/pascals-triangle-ii/
// Idea: Implementation.
// Difficulty: Easy
// Tags:
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> lastRow;
    for (int i = 1; i <= rowIndex + 1; ++i) {
      vector<int> row;
      for (int j = 0; j < i; ++j) {
        if (j == 0 || j == i - 1) {
          row.push_back(1);
        } else {
          row.push_back(lastRow[j - 1] + lastRow[j]);
        }
      }
      lastRow = row;
    }
    return lastRow;
  }
};
