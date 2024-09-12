// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 172
// Title: Factorial Trailing Zeroes
// Link: https://leetcode.com/problems/factorial-trailing-zeroes/
// Idea: Count the number of twos and fives that are factors of every number up
// to n -- the answer will be the minimum of the number of twos and fives, as
// you need a two and a five to make ten (which leads to a trailing zero). There
// are some optimizations possible, e.g., there will always be more than enough
// twos, so you really only need to count the number of fives.
// Difficulty: Easy
// Tags: Math
class Solution {
 public:
  int trailingZeroes(int n) {
    int twos = 0, fives = 0;
    for (int i = 1; i <= n; ++i) {
      int x = i;
      // Extract all the twos and fives in x.
      while (true) {
        if (x % 2 == 0) {
          x /= 2;
          ++twos;
        } else if (x % 5 == 0) {
          x /= 5;
          ++fives;
        } else {
          break;
        }
      }
    }
    return min(twos, fives);
  }
};
