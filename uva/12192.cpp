// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12192
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

int area[550][550];

int main() {
  int n, m, q;
  while (GET(n) && GET(m) && n != 0 && m != 0) {
    FOR(i, 0, n) {
      FOR(j, 0, m) { GET(area[i][j]); }
    }

    GET(q);
    int lo, hi;
    while (q--) {
      GET(lo);
      GET(hi);

      // On each row, find the place where the grid could start, and check if it
      // is within the upper bound. Then, expand diagonally until the next
      // diagonal square is too large.
      int mx_size = 0;
      for (int i = 0; i < n; ++i) {
        int begin_pos = lower_bound(area[i], area[i] + m, lo) - area[i];
        int size;
        for (size = 0; i + size < n && begin_pos + size < m &&
                       area[i + size][begin_pos + size] <= hi;
             ++size)
          ;
        mx_size = max(size, mx_size);
      }
      printf("%d\n", mx_size);
    }
    printf("-\n");
  }
  return 0;
}
