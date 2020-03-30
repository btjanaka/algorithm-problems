// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) dijkstrashortestreach
// Title: Dijkstra: Shortest Reach 2
// Link: https://www.hackerrank.com/challenges/dijkstrashortreach/problem
// Idea: Implement Dijkstra's algorithm.
// Difficulty: medium
// Tags: dijkstra, shortest-paths, graph
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
    int n, m, s;
    GET(n);
    GET(m);
    vector<vector<ii>> g(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      GET(u);
      GET(v);
      GET(w);
      --u;
      --v;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    GET(s);
    --s;

    vector<int> dist(n, -1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[s] = 0;
    pq.push({0, s});
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

    for (int i = 0; i < n; ++i) {
      if (i != s) printf("%d%c", dist[i], i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
