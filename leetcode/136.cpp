// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 136
// Title: Single Number
// Link: https://leetcode.com/problems/single-number/
// Idea: XOR everything.
// Difficulty: easy
// Tags: xor, math, bit-manip
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    return accumulate(nums.begin() + 1, nums.end(), nums[0],
                      [](int a, int b) { return a ^ b; });
  }
};
