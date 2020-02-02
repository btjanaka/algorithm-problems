// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeForces) 557b
// Title: Double Matrix
// Link: https://codeforces.com/contest/1162/problem/B
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int a[55][55], b[55][55];

int main() {
  int n, m;
  while (GET(n) > 0) {
    // input
    GET(m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) GET(a[i][j]);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) GET(b[i][j]);

    // super greedy - move lower numbers into one array and higher numbers into
    // another
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (a[r][c] > b[r][c]) {
          swap(a[r][c], b[r][c]);
        }
      }
    }

    // check each tile in turn
    bool ok = true;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if ((r == 0 || a[r][c] > a[r - 1][c]) &&
            (c == 0 || a[r][c] > a[r][c - 1]) &&
            (r == 0 || b[r][c] > b[r - 1][c]) &&
            (c == 0 || b[r][c] > b[r][c - 1])) {
        } else {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }

    printf(ok ? "Possible\n" : "Impossible\n");
  }
  return 0;
}
