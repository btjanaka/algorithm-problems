// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10034
// Title: Freckles
// Link:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=975
// Idea: Boruvka's Algorithm for MST
// Difficulty: easy
// Tags: graph, mst
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

using Edge = pair<pair<int, int>, double>;

struct UnionFind {
  vector<int> p, rank;
  UnionFind(int n) : p(n), rank(n, 0) { iota(p.begin(), p.end(), 0); }
  int find(int i) { return p[i] == i ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  bool join(int i, int j) {
    if (same(i, j)) return false;
    int x = find(i), y = find(j);
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        ++rank[y];
      }
    }
    return true;
  }
};

double boruvka(int n, const vector<Edge>& edges) {
  UnionFind uf(n);

  double cost = 0.0;
  int selected = 0;

  for (int i = 1; selected < n - 1 && i < n; i <<= 1) {
    // select edges to add
    vector<Edge> closest(n, {{-1, -1}, -1.0});
    for (const Edge& e : edges) {
      int u, v;
      pair<int, int> nodes;
      double d;
      tie(nodes, d) = e;
      tie(u, v) = nodes;

      int x = uf.find(u);
      int y = uf.find(v);
      if (x == y) continue;

      // if we compare between nodes instead of parent clusters, we may end up
      // adding multiple edges from one cluster to another (e.g. multiple nodes
      // in one cluster could connect to the other cluster)
      if (closest[x].second == -1.0 || d < closest[x].second) closest[x] = e;
      if (closest[y].second == -1.0 || d < closest[y].second) closest[y] = e;
    }

    // add in edges
    for (const Edge& e : closest) {
      int u, v;
      pair<int, int> nodes;
      double d;
      tie(nodes, d) = e;
      tie(u, v) = nodes;

      if (d == -1.0) continue;

      if (uf.join(u, v)) {
        ++selected;
        cost += d;
        // printf("%d -%.2lf-> %d\n", u, d, v); // debugging
      }
    }
  }

  return cost;
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n;
    GET(n);

    vector<pair<double, double>> pts;
    for (int i = 0; i < n; ++i) {
      double x, y;
      GED(x);
      GED(y);
      pts.push_back({x, y});
    }

    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double dx = pts[i].first - pts[j].first;
        double dy = pts[i].second - pts[j].second;
        double d = sqrt(dx * dx + dy * dy);
        edges.push_back({{i, j}, d});
      }
    }

    printf("%.2lf\n", boruvka(n, edges));
    if (ca) printf("\n");
  }
  return 0;
}
