// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 661
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

int main() {
  int n, m, c;
  bool status[25];  // true is on, false is off
  int currents[25];
  bool blown;
  for (int seq = 1; scanf("%d %d %d", &n, &m, &c) && n && m && c; ++seq) {
    // Record currents
    FORe(i, 1, n) { GET(currents[i]); }

    // Run simulation
    memset(status, 0, 25);
    blown = false;
    int op;
    int tot_cur = 0;
    int max_cur = 0;
    FOR(i, 0, m) {
      GET(op);
      status[op] = !status[op];
      if (status[op]) {
        tot_cur += currents[op];
        if (tot_cur > c) blown = true;
        max_cur = tot_cur > max_cur ? tot_cur : max_cur;
      } else {
        tot_cur -= currents[op];
      }
    }

    // Output
    printf("Sequence %d\n", seq);
    if (blown) {
      printf("Fuse was blown.\n");
    } else {
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n", max_cur);
    }
    PLN;
  }
  return 0;
}
