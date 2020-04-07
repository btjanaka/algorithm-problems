// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 50
// Title: Pow(x,n)
// Link: https://leetcode.com/problems/powx-n
// Idea: Use the fact that n can be represented as a series of powers of 2, i.e.
// n = 2^k + 2^(k-1) + ... 2^0. Thus, the result of x^n is really x^(2^k) *
// x^(2^(k-1)) * ... Thus, in our calculations, we just have to keep calculating
// x^(2^y) for some y and multiplying that into our accumulated result.
// Difficulty: medium
// Tags: implementation, math
class Solution {
 public:
  double myPow(double x, int n) {
    // Shortcuts
    if (n == 0) return 1.0;  // Simply return 1 for 0^0 as well
    if (x == 0 || x == 1) return x;
    if (x == -1) {
      if (n % 2 == 0) {
        return 1;
      } else {
        return -1;
      }
    }

    // *actual* calculations
    bool neg = n < 0;  // keep track if we need to invert at the end
    double res = 1.0;
    long long nn =
        n;  // for edge case when n is INT_MIN, since -INT_MIN > INT_MAX
    nn = nn > 0 ? nn : -nn;
    while (nn != 0) {
      if (nn % 2 == 0) {
        x *= x;
        nn /= 2;
      } else {
        res *= x;
        --nn;
      }
    }

    if (neg) {
      return 1 / res;
    } else {
      return res;
    }
  }
};
