// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) bigtruck
// Title: Big Truck
// Link: https://open.kattis.com/problems/bigtruck
// Idea: Use Dijkstra, but don't just prioritize by distance - prioritize by
// higher value, so that if two nodes are at the same distance, choose the one
// with the higher value.
// Difficulty: medium
// Tags: graph, dijkstra
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

  // Input
  int n;
  while (cin >> n) {  // support multiple inputs
    vi t(n + 1);
    for (int i = 1; i <= n; ++i) cin >> t[i];
    int m;
    cin >> m;
    vector<vector<ii>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int a, b, d;
      cin >> a >> b >> d;
      g[a].push_back({b, d});
      g[b].push_back({a, d});
    }

    // Dijkstra - the PQ prioritizes shortest distance and highest value
    using ii_i = pair<ii, int>;  // { { distance, negative value }, node }
    vi dist(n + 1, -1);
    vi val(n + 1, -1);
    priority_queue<ii_i, vector<ii_i>, greater<ii_i>> pq;

    dist[1] = 0;
    val[1] = t[1];
    pq.push({{0, -t[1]}, 1});

    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      int du = cur.first.first;
      int uval = -cur.first.second;
      int u = cur.second;

      // Dead nodes are now ones that have too much distance, and ones that have
      // same distance but too little value.
      if (du > dist[u] || du == dist[u] && uval < val[u]) continue;

      for (const auto& edge : g[u]) {
        int v = edge.first, w = edge.second;
        // We found a better node if the distance was shorter or the distance
        // was the same but there was a better value.
        if (dist[v] == -1 || dist[u] + w < dist[v] ||
            (dist[u] + w == dist[v] && uval + t[v] > val[v])) {
          dist[v] = dist[u] + w;
          val[v] = uval + t[v];
          pq.push({{dist[v], -val[v]}, v});
        }
      }
    }

    // Output
    if (dist[n] == -1) {
      cout << "impossible\n";
    } else {
      cout << dist[n] << ' ' << val[n] << '\n';
    }
  }
  return 0;
}
