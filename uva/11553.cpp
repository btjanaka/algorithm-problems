// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11553
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  for (int _i = 0; _i < len; ++_i) {              \
    if (_i != len - 1) {                          \
      printf("%d ", arr[_i]);                     \
    } else {                                      \
      printf("%d\n", arr[_i]);                    \
    }                                             \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int grid[9][9];

int main() {
  int t, n;
  GET(t);
  while (t--) {
    GET(n);
    FOR(r, 0, n) {
      FOR(c, 0, n) { GET(grid[r][c]); }
    }

    // Try all n! combos of choices.
    // Note: Key is to keep track of minimum possible score - Bob will always
    // play to get as much as he can.
    // Bob has complete control of the game, because he gets to pick which
    // number specifically gets chosen. Alice eventually has to pick every row,
    // but Bob can pick the specific number in each row. So he just has to
    // minimize the amount he loses.
    int cols[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int mn = 0;
    FOR(r, 0, n) { mn += grid[r][cols[r]]; }
    while (next_permutation(cols, cols + n)) {
      int tmp = 0;
      FOR(r, 0, n) { tmp += grid[r][cols[r]]; }
      if (tmp < mn) mn = tmp;
    }
    printf("%d\n", mn);
  }
  return 0;
}
