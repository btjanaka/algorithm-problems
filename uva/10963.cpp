// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10963
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
  while (t--) {
    bool fix = true;
    int ref_gap = 0;
    int cols;
    GET(cols);
    for (int i = 0; i < cols; ++i) {
      int y1, y2;
      scanf("%d %d", &y1, &y2);
      int len = y1 - y2;
      if (i == 0) {
        ref_gap = len;
      } else {
        fix &= len == ref_gap;
      }
    }
    if (fix) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
    if (t) PLN;
  }
  return 0;
}
