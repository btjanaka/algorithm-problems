// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1193
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

// left and right edge that the radar can be placed and still cover that island
pair<double, double> islands[1010];

int main() {
  int n;
  double d;
  for (int ca = 1; scanf("%d %lf", &n, &d) && !(!n && !d); ++ca) {
    bool imp = false;  // impossible
    // For each island, the interval is the range of locations where a radar
    // station can be and still reach the island.
    FOR(i, 0, n) {
      double x, y, dx;
      scanf("%lf %lf", &x, &y);
      if (y > d) {
        imp = true;  // No solution if y is too large
        continue;
      }
      dx = sqrt((d * d) - (y * y));
      islands[i].first = x - dx;
      islands[i].second = x + dx;
    }

    int tot;
    if (imp) {
      tot = -1;
    } else {
      tot = 0;
      sort(islands, islands + n);
      // printf("d: %lf\n", d);
      // for (int i = 0; i < n; ++i) {
      //   printf("%lf %lf\n", islands[i].first, islands[i].second);
      // }

      for (int isl_i = 0; isl_i < n;) {
        ++tot;
        // Advance isl_i until the radar station would no longer cover the
        // current one - also have to make sure the radar station covers all the
        // ones in between that we claim to cover, so we also have to use the
        // smallest endpoint of the stations we cover.
        int i;
        double endpoint = islands[isl_i].second;
        for (i = isl_i; i < n; ++i) {
          if (islands[i].first > endpoint) {
            break;
          }
          if (islands[i].second < endpoint) {
            endpoint = islands[i].second;
          }
        }
        isl_i = i;
      }
    }

    printf("Case %d: %d\n", ca, tot);
  }
  return 0;
}
