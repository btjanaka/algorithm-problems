// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11679
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

int banks[25];  // 1-indexed

int main() {
  int b, n;
  while (scanf("%d %d", &b, &n) && b != 0 && n != 0) {
    memset(banks, 0, sizeof(banks));
    for (int i = 1; i <= b; ++i) {
      GET(banks[i]);
    }
    int d, c, v;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d %d", &d, &c, &v);
      banks[d] -= v;
      banks[c] += v;
    }

    // Check all banks to see if any are in debt
    int good = true;
    for (int i = 1; i <= b; ++i) {
      good &= banks[i] >= 0;
    }
    putchar(good ? 'S' : 'N');
    PLN;
  }
  return 0;
}
