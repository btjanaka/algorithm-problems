// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11581
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

void f(int g[3][3]) {
  int res[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int tot = 0;
      if (i > 0) tot += g[i - 1][j];
      if (j > 0) tot += g[i][j - 1];
      if (i < 2) tot += g[i + 1][j];
      if (j < 2) tot += g[i][j + 1];
      res[i][j] = tot % 2;
    }
  }
  memcpy(g, res, sizeof(res));
}

int main() {
  int g[3][3];
  int ca;
  GET(ca);
  while (ca--) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        scanf("%1d", &g[i][j]);
      }
    }
    // infinite when applying f yields the same result
    // no solution to the problem when f always is same to begin with
    int old[3][3];
    int res = 0;
    while (true) {
      memcpy(old, g, sizeof(old));
      f(g);
      bool same = true;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          same &= old[i][j] == g[i][j];
        }
      }
      if (same) {
        --res;
        break;
      }
      ++res;
    }
    printf("%d\n", res);
  }
  return 0;
}
