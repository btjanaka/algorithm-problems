// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 7
// Title: Reverse Integer
// Link: https://leetcode.com/problems/reverse-integer
// Idea:
// Difficulty: easy
// Tags: math, implementation
class Solution {
 public:
  int reverse(int x) {
    int sign = x > 0 ? 1 : -1;
    x = abs(x);

    // Count number of digits
    int num_digits, copy = x;
    for (num_digits = 0; copy > 0; copy /= 10) {
      ++num_digits;
    }

    // Reverse number
    long long res = 0;
    for (int i = num_digits - 1; i >= 0; --i) {
      res += (x % 10) * pow(10, i);
      x /= 10;
    }

    res *= sign;

    // Bounds check
    if (res > INT_MAX || res < INT_MIN) {
      return 0;
    }
    return res;
  }
};
