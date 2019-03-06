// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10986
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    int n, m, s, t;
    GET(n);
    GET(m);
    GET(s);
    GET(t);

    vector<vector<ii>> g(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      GET(u);
      GET(v);
      GET(w);
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }

    vector<int> dist(n, -1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
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

    printf("Case #%d: ", caa);
    if (dist[t] == -1) {
      printf("unreachable\n");
    } else {
      printf("%d\n", dist[t]);
    }
  }
  return 0;
}
