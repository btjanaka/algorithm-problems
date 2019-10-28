// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) slowleak
// Title: Slow Leak
// Link: https://open.kattis.com/problems/slowleak
// Idea: Use Dijkstra at each repair station, home, and school, to find the
// shortest distance to the other repair stations, home, and school. This
// results in a new graph with only repair stations, home, and school - run
// Dijkstra again on this graph to find the answer.
// Difficulty: medium
// Tags: dijkstra, graph
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  ll n, m, t, mxd;
  cin >> n >> m >> t >> mxd;

  // Take in repair stations, but add on the home and school.
  vector<ll> repair_stations;
  for (ll i = 0; i < t; ++i) {
    ll x;
    cin >> x;
    repair_stations.push_back(x);
  }
  repair_stations.push_back(1);
  repair_stations.push_back(n);

  using li = pair<ll, ll>;          // Please, don't ask why I used this alias.
  vector<vector<li>> graph(n + 1);  // Original graph.
  vector<vector<li>> g2(n + 1);     // Only repair stations, home, and school.

  for (ll i = 0; i < m; ++i) {
    ll u, v;
    ll d;
    cin >> u >> v >> d;
    graph[u].push_back({v, d});
    graph[v].push_back({u, d});
  }

  // Use Dijkstra from each repair station to find the shortest distance to the
  // other repair stations and construct a new graph based on these distances.
  for (ll r : repair_stations) {
    vector<ll> dist(n + 1, -1);
    dist[r] = 0;
    priority_queue<li, vector<li>, greater<li>> pq;
    pq.push({0, r});
    while (!pq.empty()) {
      ll u, du;
      tie(du, u) = pq.top();
      pq.pop();
      if (du > dist[u]) continue;
      for (const auto& edge : graph[u]) {
        ll v = edge.first;
        ll d = edge.second;
        if (dist[v] == -1 || dist[u] + d < dist[v]) {
          dist[v] = dist[u] + d;
          pq.push({dist[v], v});
        }
      }
    }

    // Add the edges to the other repair stations to the new graph, but only if
    // the other stations were reachable and were not too far away.
    for (ll j : repair_stations) {
      if (j == r) continue;
      if (dist[j] != -1 && dist[j] <= mxd) {
        g2[r].push_back({j, dist[j]});
      }
    }
  }

  // Find the shortest path in the graph of repair station distances. If no path
  // is found, the distance will be -1.
  vector<ll> dist(n + 1, -1);
  dist[1] = 0;
  priority_queue<li, vector<li>, greater<li>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    ll u, du;
    tie(du, u) = pq.top();
    pq.pop();
    if (du > dist[u]) continue;
    for (const auto& edge : g2[u]) {
      ll v = edge.first;
      ll d = edge.second;
      if (dist[v] == -1 || dist[u] + d < dist[v]) {
        dist[v] = dist[u] + d;
        pq.push({dist[v], v});
      }
    }
  }

  // Output
  if (dist[n] == -1) {
    cout << "stuck" << endl;
  } else {
    cout << dist[n] << endl;
  }

  return 0;
}
