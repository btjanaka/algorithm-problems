// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 190
// Title: Reverse Bits
// Link: https://leetcode.com/problems/reverse-bits/
// Idea: Use bitwise operations to grab the bits from n and put them into res.
// Difficulty: Easy
// Tags:
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
      res = res << 1;
      res = (res | (n & 1));
      n = n >> 1;
    }
    return res;
  }
};
