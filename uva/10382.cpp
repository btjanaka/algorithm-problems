// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10382
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

// 0: left endpoint
// 1: diameter
pair<double, double> sprinklers[10010];

int main() {
  int n;
  double l, w;
  while (scanf("%d %lf %lf", &n, &l, &w) > 0) {
    FOR(i, 0, n) {
      double pos, rad;
      scanf("%lf %lf", &pos, &rad);
      double dx = rad * rad - (w / 2.0) * (w / 2.0);
      if (dx < 0) {
        dx = 0;
      } else {
        dx = sqrt(dx);
      }
      sprinklers[i].first = pos - dx;
      sprinklers[i].second = 2 * dx;
    }

    // for (int i = 0; i < n; ++i)
    //   printf("%lf %lf\n", sprinklers[i].first, sprinklers[i].second);
    sort(sprinklers, sprinklers + n);

    int tot = 0;
    double pos = 0.0;
    int spr_i = 0;
    while (pos < l) {
      double max_r = -1.0;
      while (spr_i < n && sprinklers[spr_i].first <= pos) {
        double right = sprinklers[spr_i].first + sprinklers[spr_i].second;
        if (right > max_r) {
          max_r = right;
        }
        ++spr_i;
      }
      // Could not find anything to extend the line
      if (max_r == -1) {
        tot = -1;
        break;
      }
      pos = max_r;
      ++tot;
    }

    printf("%d\n", tot);
  }
  return 0;
}
