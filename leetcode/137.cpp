// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 137
// Title: Single Number II
// Link: https://leetcode.com/problems/single-number-ii/
// Idea: Count the number of times each bit occurs in numbers in the array, and
// if the number of its occurrences is not divisible by 3, add that bit to the
// result. This is technically linear because we go through the array a set
// number of times.
// Difficulty: medium
// Tags: array, bit-manipulation
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      int cur = 1 << i;
      int num_occurrences = 0;
      for (int num : nums) {
        num_occurrences += !!(cur & num);
      }
      if (num_occurrences % 3) res |= cur;
    }
    return res;
  }
};
