// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10465
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

// Make a table of time where each entry represents how many burgers Homer can
// eat at that time - so at each time entry we can see how many burgers Homer
// can eat - if at all. The idea is that at each time we find the maximum
// burgers Homer can eat.
int dp[10010];

int main() {
  int m, n, t;
  while (GET(m) > 0) {
    GET(n);
    GET(t);
    memset(dp, 0, sizeof(dp));
    if (n <= t) dp[n] = 1;
    if (m <= t) dp[m] = 1;
    for (int i = 0; i <= t; ++i) {
      // We can only assess burgers if this one actually has burgers
      if (dp[i] > 0) {
        // Next times are maximum of the one they have right now and this one
        // plus 1
        if (i + n <= t) dp[i + n] = max(dp[i + n], dp[i] + 1);
        if (i + m <= t) dp[i + m] = max(dp[i + m], dp[i] + 1);
      }
    }
    int burg = 0;
    int beer = t;
    for (int i = t; i >= 0; --i) {
      if (dp[i] > 0) {
        burg = dp[i];
        beer = t - i;
        break;
      }
    }

    // output
    printf("%d", burg);
    if (beer) {
      printf(" %d\n", beer);
    } else {
      printf("\n");
    }
  }
  return 0;
}
