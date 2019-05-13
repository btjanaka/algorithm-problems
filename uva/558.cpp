// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 558
// Idea: Use Bellman-Ford, and if it makes changes for more than n cycles, there
// is a negative cycle.
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, m;
    GET(n);
    GET(m);
    vector<vector<ii>> g(n);
    for (int i = 0; i < m; ++i) {
      int x, y, t;
      GET(x);
      GET(y);
      GET(t);
      g[x].push_back({y, t});
    }

    vector<int> d(n, INT_MAX);
    d[0] = 0;
    bool ok = false;
    for (int i = 1;; ++i) {
      bool change = false;
      for (int u = 0; u < n; ++u) {
        for (int j = 0; j < g[u].size(); ++j) {
          int v, w;
          tie(v, w) = g[u][j];
          if (d[u] + w < d[v]) {
            change = true;
            d[v] = d[u] + w;
          }
        }
      }

      if (!change && i <= n) {
        break;
      } else if (i > n) {
        ok = true;
        break;
      }
    }

    printf(ok ? "possible\n" : "not possible\n");
  }
  return 0;
}
