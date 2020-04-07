// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 29
// Title: Divide Two Integers
// Link: https://leetcode.com/problems/divide-two-integers
// Idea: Gradually subtract. Use bit-shifting in place of multiplication.
// Difficulty: medium
// Tags: math, implementation
class Solution {
 public:
  int divide(int dividend, int divisor) {
    // Shortcuts
    if (divisor == 0) return -1;
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
      if (dividend == INT_MIN) return INT_MAX;
      return -dividend;
    }

    // Determine negatives
    bool neg_dividend = dividend < 0;
    bool neg_divisor = divisor < 0;

    // Remove signs
    // Account for -INT_MIN, which is greater than INT_MAX
    long long dividend_ll = dividend;
    long long divisor_ll = divisor;
    dividend_ll = dividend_ll < 0 ? -dividend_ll : dividend_ll;
    divisor_ll = divisor_ll < 0 ? -divisor_ll : divisor_ll;

    // Find how much the divisor can be shifted until it exceeds
    // dividend - Note: this has to be a <=, since dividend_ll/divisor_ll
    // could be a power of 2
    int power;
    for (power = 0; (divisor_ll << (power + 1)) <= dividend_ll; ++power)
      ;

    // Gradually subtract from dividend
    long long res = 0;
    for (int i = power; i >= 0; --i) {
      if ((divisor_ll << i) <= dividend_ll) {
        dividend_ll -= (divisor_ll << i);
        res += 1 << i;
      }
    }

    // Apply negative signs
    return neg_dividend ^ neg_divisor ? -res : res;
  }
};
