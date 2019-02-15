// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) matrix
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
typedef long long ll;
using namespace std;

int main() {
  int a, b, c, d;
  for (int ca = 1; scanf("%d %d %d %d", &a, &b, &c, &d) > 0; ++ca) {
    int det = a * d - b * c;
    printf("Case %d:\n%d %d\n%d %d\n", ca, d / det, -b / det, -c / det,
           a / det);
  }
  return 0;
}
