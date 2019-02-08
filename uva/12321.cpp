// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12321
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

pair<int, int> stations[10010];

int main() {
  int l, g;
  while (GET(l) && GET(g) && !(!l && !g)) {
    FOR(i, 0, g) {
      int x, r;
      GET(x);
      GET(r);
      stations[i].first = x - r;
      stations[i].second = x + r;
    }

    sort(stations, stations + g);

    int pos = 0;
    int tot = 0;
    int station_i = 0;
    bool ok = true;
    while (pos < l) {
      int max_r = -1;
      for (; station_i < g && stations[station_i].first <= pos; ++station_i) {
        if (stations[station_i].second > max_r) {
          max_r = stations[station_i].second;
        }
      }

      pos = max_r;
      ++tot;

      if (max_r == -1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      printf("%d\n", g - tot);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
