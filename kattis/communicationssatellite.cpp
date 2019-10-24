// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) communicationssatellite
// Title: Communications Satellite
// Link: https://open.kattis.com/problems/communicationssatellite
// Idea: Build MST
// Difficulty: medium
// Tags: mst, graph
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct UnionFind {
  vi p, rank;
  UnionFind(int n) : p(n), rank(n, 0) { iota(p.begin(), p.end(), 0); }
  int find(int i) { return p[i] == i ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  void join(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
      }
    }
  }
};

int main() {
  int n;
  GET(n);
  double coords[n][3];
  vector<pair<double, pair<int, int>>> edges;
  for (int i = 0; i < n; ++i) {
    GED(coords[i][0]);
    GED(coords[i][1]);
    GED(coords[i][2]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      double x1 = coords[i][0], y1 = coords[i][1], x2 = coords[j][0],
             y2 = coords[j][1];
      double r1 = coords[i][2], r2 = coords[j][2];
      double dx = x1 - x2;
      double dy = y1 - y2;
      double d = sqrt(dx * dx + dy * dy) - r1 - r2;
      edges.push_back({d, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());

  UnionFind uf(n);
  double cost = 0.0;
  for (const auto& edge : edges) {
    double d = edge.first;
    int i = edge.second.first;
    int j = edge.second.second;
    if (!uf.same(i, j)) {
      uf.join(i, j);
      cost += d;
    }
  }

  printf("%.9lf\n", cost);

  return 0;
}
