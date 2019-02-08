// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11292
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

int heads[20020];
int knights[20020];

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) && !(!n && !m)) {
    FOR(i, 0, n) GET(heads[i]);
    FOR(i, 0, m) GET(knights[i]);
    sort(heads, heads + n);
    sort(knights, knights + m);
    int kn = 0;
    int tot = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      // Advance kn until we find a big enough knight
      for (; kn < m && knights[kn] < heads[i]; ++kn)
        ;
      if (kn == m) {
        ok = false;
        break;
      } else {
        tot += knights[kn];
        ++kn;
      }
    }
    if (ok) {
      printf("%d\n", tot);
    } else {
      printf("Loowater is doomed!\n");
    }
  }
  return 0;
}
