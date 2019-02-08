// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12032
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

int rungs[101000];

// See whether can make it with this strength.
bool sim(int n, int k) {
  int cur = 0;
  FOR(i, 0, n) {
    if (cur + k < rungs[i]) return false;
    if (cur + k == rungs[i]) --k;
    cur = rungs[i];
  }
  return true;
}

int main() {
  int t;
  int n;
  GET(t);
  FORe(ca, 1, t) {
    GET(n);
    FOR(i, 0, n) GET(rungs[i]);

    int lo = 0, hi = 10000000, mid = 0, k = 0;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      if (sim(n, mid)) {
        hi = mid;
        k = mid;
      } else {
        lo = mid + 1;
        k = mid + 1;
      }
    }
    printf("Case %d: %d\n", ca, k);
  }
  return 0;
}
