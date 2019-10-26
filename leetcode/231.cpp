// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 231
// Title: Power of Two
// Link: https://leetcode.com/problems/power-of-two/
// Idea: If the number is a power of two, AND'ing it with the number before it
// should give 0. Edge case is when n is 0.
// Difficulty: easy
// Tags: bit-manipulation
class Solution {
 public:
  bool isPowerOfTwo(long long n) { return n ? !(n & (n - 1)) : false; }
};
