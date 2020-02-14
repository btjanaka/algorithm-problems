// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeForces) 1144f
// Title: Graph Without Long Directed Paths
// Link: https://codeforces.com/contest/1144/problem/F
// Idea: Check if the graph is bipartite. If so, it will have a solution.
// Difficulty: medium
// Tags: graph, bipartite, bfs
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  // Input.
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<ii> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // Check bipartite via BFS. This is done by attempting to find a bicoloring
  // for the graph.
  bool ok = true;
  queue<int> q;
  const int UNVISITED = 2;
  vector<int> color(n + 1, UNVISITED);  // Colors are 0 and 1

  q.push(1);  // Since the graph is connected, we can start anywhere.
  color[1] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (color[v] == color[u]) {
        // Color conflict.
        ok = false;
        break;
      } else if (color[v] == UNVISITED) {
        q.push(v);
        color[v] = 1 - color[u];
      }
    }
    if (!ok) break;
  }

  if (ok) {
    cout << "YES\n";
    // Output edge directions.
    for (const auto& edge : edges)
      cout << color[edge.first];  // Just output the color.
    cout << '\n';
  } else {
    cout << "NO\n";
  }

  return 0;
}
