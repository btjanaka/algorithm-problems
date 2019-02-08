// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12210
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

int bach[10010];

int main() {
  int b, s;
  for (int ca = 1; scanf("%d %d", &b, &s) && !(!b && !s); ++ca) {
    FOR(i, 0, b) GET(bach[i]);
    FOR(i, 0, s) scanf("%*d");  // spinsters don't even matter?
    sort(bach, bach + b);
    if (b <= s) {
      printf("Case %d: 0\n", ca);
    } else {
      printf("Case %d: %d %d\n", ca, b - s, bach[0]);
    }
  }
  return 0;
}
