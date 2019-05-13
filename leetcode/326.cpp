// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 326
// Title: Power of Three
// Link: https://leetcode.com/problems/power-of-three/
// Idea: Keep recurring until you get to 1.
// Difficulty: easy
// Tags: math, exponents
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 0) return false;
    if (n == 1) return true;
    return n % 3 == 0 && isPowerOfThree(n / 3);
  }
};
