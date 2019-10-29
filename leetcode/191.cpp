// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 191
// Title: Number of 1 Bits
// Link: https://leetcode.com/problems/number-of-1-bits/
// Idea: There are two "good enough" solutions. One is to iterate through the
// bits of n one at a time and count which ones are on. A faster way,
// implemented here, is to keep finding the least significant bit of n and
// subtracting it from n (in this case, we use XOR instead because it is
// faster).
// Difficulty: easy
// Tags: bit-manipulation
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int i = 0;
    for (; n; ++i, n = n ^ (n & -n))
      ;
    return i;
  }
};
