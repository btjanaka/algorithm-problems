// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11413
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

int milk[1100];

// Tell if the max capacity will work - simulate filling milk jars.
bool simulate(int n, int m, int mx) {
  int milk_i = 0;
  for (int i = 0; i < m && milk_i < n; ++i) {
    int cur = 0;
    while (milk_i < n && cur + milk[milk_i] <= mx) {
      cur += milk[milk_i++];
    }
  }
  return milk_i == n;
}

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) > 0) {
    int hi = 0;
    FOR(i, 0, n) {
      GET(milk[i]);
      hi += milk[i];
    }

    int lo = 0, mid = 0, ans = 0;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      if (simulate(n, m, mid)) {
        hi = mid;
        ans = mid;
      } else {
        lo = mid + 1;
        ans = mid + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
