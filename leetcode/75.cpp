// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 75
// Title: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/
// Idea: Store the 0's at the start, 2's at the beginning
// Difficulty: medium
// Tags: sort, list, array
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int cur = 0;
    int zeros = 0;
    int twos = n - 1;
    while (cur <= twos) {
      switch (nums[cur]) {
        case 0:
          swap(nums[cur], nums[zeros]);
          ++zeros;
        case 1:
          ++cur;
          break;
        case 2:
          swap(nums[cur], nums[twos]);
          --twos;
          break;
      }
    }
  }
};
