// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11900
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

int eggs[40];

int main() {
  int t;
  GET(t);
  FORe(ca, 1, t) {
    int n, p, q;
    GET(n);
    GET(p);
    GET(q);
    FOR(i, 0, n) GET(eggs[i]);  // eggs are already sorted

    // Simply get all the small eggs we can!
    int tot = 0;
    int weight = 0;
    int lim = min(p, n);
    FOR(i, 0, lim) {
      if (weight + eggs[i] <= q) {
        ++tot;
        weight += eggs[i];
      } else {
        break;
      }
    }
    printf("Case %d: %d\n", ca, tot);
  }
  return 0;
}
