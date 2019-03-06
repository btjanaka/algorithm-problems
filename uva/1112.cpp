// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1112
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, e, t, m;
    GET(n);
    GET(e);
    --e;
    GET(t);
    GET(m);

    vector<vector<ii>> g(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      GET(u);
      GET(v);
      GET(w);
      --u;
      --v;
      g[v].push_back({u, w});
    }

    // dijkstra
    vector<int> dist(n, -1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, e});
    dist[e] = 0;
    while (!pq.empty()) {
      ii cur = pq.top();
      pq.pop();
      int d = cur.first, u = cur.second;
      if (d > dist[u] && dist[u] != -1) continue;
      for (ii child : g[u]) {
        int v = child.first, w = child.second;
        if (dist[v] == -1 || dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }

    int tot = 0;
    for (int i = 0; i < n; ++i) {
      if (dist[i] <= t && dist[i] >= 0) {
        ++tot;
      }
    }
    printf("%d\n", tot);

    if (ca) printf("\n");
  }
  return 0;
}
