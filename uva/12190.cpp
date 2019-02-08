// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12190
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

ll price(int cwh) {
  ll res = 0;
  if (cwh > 1000000) {
    res += 7L * (cwh - 1000000);
    cwh = 1000000;
  }
  if (cwh > 10000) {
    res += 5L * (cwh - 10000);
    cwh = 10000;
  }
  if (cwh > 100) {
    res += 3L * (cwh - 100);
    cwh = 100;
  }
  if (cwh > 0) {
    res += 2L * (cwh - 0);
    cwh = 0;
  }
  return res;
}

int main() {
  ll a, b;
  while (scanf("%lld %lld", &a, &b) && !(!a && !b)) {
    // Binary search for the total consumption, i.e. the amt that gives |a|
    int lo = 0, hi = 1000000000, mid = 0, tot = 0;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      ll p = price(mid);
      if (p == a) {
        tot = mid;
        break;
      } else if (p > a) {
        hi = mid - 1;
        tot = mid - 1;
      } else {
        lo = mid + 1;
        tot = mid + 1;
      }
    }

    // Binary search for the correct usage, and hence the amount you have to
    // pay.
    lo = 0, hi = tot / 2, mid = 0;
    int use = 0;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      int neigh = tot - mid;
      ll diff = price(neigh) - price(mid);
      if (diff == b) {
        use = mid;
        break;
      } else if (diff < b) {
        hi = mid - 1;
        use = mid - 1;
      } else {
        lo = mid + 1;
        use = mid + 1;
      }
    }

    printf("%lld\n", price(use));
  }
  return 0;
}
