// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11764
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int main() {
  int t;
  GET(t);
  FORe(c, 1, t) {
    int n;
    GET(n);
    int hi = 0, lo = 0;
    int prev;
    int curr;
    for (int i = 0; i < n; ++i) {
      GET(curr);
      if (i != 0) {
        if (curr > prev) {
          ++hi;
        }
        if (prev > curr) {
          ++lo;
        }
      }
      prev = curr;
    }
    printf("Case %d: %d %d\n", c, hi, lo);
  }
  return 0;
}
