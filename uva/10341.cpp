// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10341
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

double calc(int p, int q, int r, int s, int t, int u, double x) {
  return exp(-x) * p + sin(x) * q + cos(x) * r + tan(x) * s + (x * x) * t + u;
}

int main() {
  int p, q, r, s, t, u;
  while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) > 0) {
    double lo = 0.0, hi = 1.0, mid = 0.0, ans = 0.0;
    while (hi - lo > 1e-9) {
      mid = (hi + lo) / 2.0;
      double res = calc(p, q, r, s, t, u, mid);
      if (res > 0) {
        lo = mid;
        ans = mid;
      } else {
        hi = mid;
      }
    }
    if (abs(calc(p, q, r, s, t, u, ans)) > 1e-4) {
      printf("No solution\n");
    } else {
      printf("%.4lf\n", ans);
    }
  }
  return 0;
}
