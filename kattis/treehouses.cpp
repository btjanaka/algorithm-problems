// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) treehouses
// Title: Treehouses
// Link: https://open.kattis.com/problems/treehouses
// Idea: Kruskal's algorithm, but start by joining the e treehouses that are
// connected by open land, as well as the p pairs of treehouses that are already
// connected.
// Difficulty: medium
// Tags: minimum-spanning-tree, mst, kruskal, graph
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct UnionFind {
  vector<int> p, rank;
  UnionFind(int n) : p(n), rank(n, 0) { iota(p.begin(), p.end(), 0); }
  int find(int i) { return i == p[i] ? p[i] : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  bool join(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] < rank[y]) {
        p[x] = y;
      } else {
        p[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
      }
      return true;
    }
    return false;
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, e, p;
  cin >> n >> e >> p;
  UnionFind uf(n);
  double cost = 0.0;

  // Input positions
  vector<pair<double, double>> pos(n);
  for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;

  // Join first e treehouses
  for (int i = 1; i < e; ++i) uf.join(i, i - 1);
  // Join p already-made cables
  for (int i = 0; i < p; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    uf.join(a, b);
  }

  // Join everything else
  vector<pair<double, pair<int, int>>> edges;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double dx = pos[j].first - pos[i].first;
      double dy = pos[j].second - pos[i].second;
      double dist = sqrt(dx * dx + dy * dy);
      edges.push_back({dist, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());
  for (const auto& edge : edges) {
    if (uf.join(edge.second.first, edge.second.second)) cost += edge.first;
  }

  cout << cost << endl;

  return 0;
}
