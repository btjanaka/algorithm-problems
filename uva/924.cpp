// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 924
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int e;
  GET(e);
  vector<vector<int>> g(e);
  for (int u = 0; u < e; ++u) {
    int n;
    GET(n);
    for (int j = 0; j < n; ++j) {
      int v;
      GET(v);
      g[u].push_back(v);
    }
  }

  int t;
  GET(t);
  for (int i = 0; i < t; ++i) {
    int x;
    GET(x);
    vi days;
    queue<ii> q;
    vector<bool> visited(e, false);
    q.push({x, 0});
    visited[x] = true;
    while (!q.empty()) {
      int u, d;
      tie(u, d) = q.front();
      q.pop();
      if (d == days.size()) days.push_back(0);
      ++days[d];

      for (int v : g[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push({v, d + 1});
        }
      }
    }

    int mx = 0, mxi = 0;
    for (int i = 0; i < days.size(); ++i) {
      if (days[i] > mx || (mx == 1 && mxi == 0 && days[i] >= mx)) {
        mx = days[i];
        mxi = i;
      }
    }
    if (days.size() == 1) {
      printf("0\n");
    } else {
      printf("%d %d\n", mx, mxi);
    }
  }

  return 0;
}
