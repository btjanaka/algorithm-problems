// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 509
// Title: Fibonacci Number
// Link: https://leetcode.com/problems/fibonacci-number/
// Idea: Used template metaprogramming for fun.
// Difficulty: easy
// Tags: math
template <int n>
struct myfib {
  static const int res = myfib<n - 1>::res + myfib<n - 2>::res;
};

template <>
struct myfib<1> {
  static const int res = 1;
};

template <>
struct myfib<0> {
  static const int res = 0;
};

class Solution {
 public:
  int fib(int N) {
    switch (N) {
      case 0:
        return myfib<0>::res;
      case 1:
        return myfib<1>::res;
      case 2:
        return myfib<2>::res;
      case 3:
        return myfib<3>::res;
      case 4:
        return myfib<4>::res;
      case 5:
        return myfib<5>::res;
      case 6:
        return myfib<6>::res;
      case 7:
        return myfib<7>::res;
      case 8:
        return myfib<8>::res;
      case 9:
        return myfib<9>::res;
      case 10:
        return myfib<10>::res;
      case 11:
        return myfib<11>::res;
      case 12:
        return myfib<12>::res;
      case 13:
        return myfib<13>::res;
      case 14:
        return myfib<14>::res;
      case 15:
        return myfib<15>::res;
      case 16:
        return myfib<16>::res;
      case 17:
        return myfib<17>::res;
      case 18:
        return myfib<18>::res;
      case 19:
        return myfib<19>::res;
      case 20:
        return myfib<20>::res;
      case 21:
        return myfib<21>::res;
      case 22:
        return myfib<22>::res;
      case 23:
        return myfib<23>::res;
      case 24:
        return myfib<24>::res;
      case 25:
        return myfib<25>::res;
      case 26:
        return myfib<26>::res;
      case 27:
        return myfib<27>::res;
      case 28:
        return myfib<28>::res;
      case 29:
        return myfib<29>::res;
      case 30:
        return myfib<30>::res;
    }
    return -1;
  }
};
