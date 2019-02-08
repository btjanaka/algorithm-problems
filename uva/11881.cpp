// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11881
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

int cf[15];

double npv(int t, double irr) {
  double npv = cf[0];
  double irr_exp = 1 + irr;

  FORe(i, 1, t) {
    npv += (double)cf[i] / irr_exp;
    irr_exp *= irr + 1;
  }

  return npv;
}

int main() {
  int t;
  while (GET(t) && t) {
    FORe(i, 0, t) GET(cf[i]);

    if (cf[0] == 0 || t == 0) {
      printf("No\n");
      continue;
    }

    double lo = -1, hi = 1000000.0, mid = 0.0, ans = 0.0;
    while (hi - lo > 1e-9) {
      mid = (lo + hi) / 2.0;
      if (npv(t, mid) < 0.0) {
        hi = mid;
        ans = mid;
      } else {
        lo = mid;
        ans = mid;
      }
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
