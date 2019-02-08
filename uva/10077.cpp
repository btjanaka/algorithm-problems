// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10077
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
  int m, n;
  int res_i;
  while (scanf("%d %d", &m, &n) && !(m == 1 && n == 1)) {
    res_i = 0;

    // Keep track of left and right in the sequence, and do a binary search for
    // the result.
    int left[2] = {0, 1};
    int right[2] = {1, 0};
    int curr[2] = {1, 1};
    double res_frac = (double)m / n;
    while (!(curr[0] == m && curr[1] == n)) {
      // printf("%d %d\n", curr[0], curr[1]);
      double curr_frac = (double)curr[0] / curr[1];
      if (res_frac > curr_frac) {
        left[0] = curr[0];
        left[1] = curr[1];
        putchar('R');
      } else if (res_frac < curr_frac) {
        right[0] = curr[0];
        right[1] = curr[1];
        putchar('L');
      }
      curr[0] = left[0] + right[0];
      curr[1] = left[1] + right[1];
    }
    PLN;
  }
  return 0;
}
