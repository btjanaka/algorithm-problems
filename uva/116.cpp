// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 116
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct data {
  int val;
  int nr;
  int nc;
  data() : val(-1), nr(-1), nc(-1) {}
};

int m, n;
int g[110][110];
data dp[110][110];
data f(int r, int c) {
  if (dp[r][c].val != -1) return dp[r][c];
  if (c == n - 1) {
    dp[r][c].val = g[r][c];
    return dp[r][c];
  }

  // determine next rows - careful because we want to analyze in lexicographical
  // order
  int next_r[3];
  if (r == 0) {
    next_r[0] = 0;
    next_r[1] = (r + 1) == m ? 0 : (r + 1);
    next_r[2] = m - 1;
  } else if (r == m - 1) {
    next_r[0] = 0;
    next_r[1] = (r - 1) == -1 ? (m - 1) : (r - 1);
    next_r[2] = m - 1;
  } else {
    next_r[0] = r - 1;
    next_r[1] = r;
    next_r[2] = r + 1;
  }

  // find min
  dp[r][c].val = INT_MAX;
  dp[r][c].nc = c + 1;
  for (int i = 0; i < 3; ++i) {
    int res = g[r][c] + f(next_r[i], c + 1).val;
    if (res < dp[r][c].val) {
      dp[r][c].val = res;
      dp[r][c].nr = next_r[i];
    }
  }

  return dp[r][c];
}

int main() {
  while (scanf("%d %d", &m, &n) > 0) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        GET(g[i][j]);
      }
    }

    // find min row
    int mn_r = -1;
    data mn;
    mn.val = INT_MAX;
    for (int sr = 0; sr < m; ++sr) {
      for (int i = 0; i < 110; ++i) {
        for (int j = 0; j < 110; ++j) {
          dp[i][j] = data();
        }
      }
      data res = f(sr, 0);
      if (res.val < mn.val) {
        mn = res;
        mn_r = sr;
      }
    }
    f(mn_r, 0);  // get back the path data

    // output
    data cur = mn;
    int cur_r = mn_r;
    bool first = true;
    while (cur.nr != -1) {
      if (first)
        first = false;
      else
        putchar(' ');
      printf("%d", cur_r + 1);
      cur_r = cur.nr;
      cur = dp[cur.nr][cur.nc];
    }
    printf("%s%d\n", first ? "" : " ", cur_r + 1);
    printf("%d\n", mn.val);
  }
  return 0;
}
