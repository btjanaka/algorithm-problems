// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11228
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> p, rank;
  int comps;
  UnionFind(int n) : p(n), rank(n, 0) {
    iota(p.begin(), p.end(), 0);
    comps = n;
  }
  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  void join(int i, int j) {
    if (!same(i, j)) {
      --comps;
      int x = find(i), y = find(j);
      if (rank[x] < rank[y]) {
        p[x] = y;
      } else {
        p[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
      }
    }
  }
};

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    int n;
    double r;
    GET(n);
    GED(r);

    double coords[n][2];
    for (int i = 0; i < n; ++i) {
      GED(coords[i][0]);
      GED(coords[i][1]);
    }

    // Create two sets of edges
    vector<pair<double, ii>> roads, railroads;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double dx = coords[j][0] - coords[i][0];
        double dy = coords[j][1] - coords[i][1];
        double d = sqrt(dx * dx + dy * dy);
        if (d <= r) {
          roads.push_back({d, {i, j}});
        } else {
          railroads.push_back({d, {i, j}});
        }
      }
    }
    sort(roads.begin(), roads.end());
    sort(railroads.begin(), railroads.end());

    // Results
    int states = 0;
    double road_cost = 0.0;
    double railroad_cost = 0.0;
    UnionFind uf(n);

    // Select roads
    for (const pair<double, ii>& road : roads) {
      double cost = road.first;
      int u = road.second.first, v = road.second.second;

      if (uf.same(u, v)) continue;

      uf.join(u, v);
      road_cost += cost;
    }

    // Determine number of states
    states = uf.comps;

    // Select railroads
    for (const pair<double, ii>& railroad : railroads) {
      double cost = railroad.first;
      int u = railroad.second.first, v = railroad.second.second;

      if (uf.same(u, v)) continue;

      uf.join(u, v);
      railroad_cost += cost;
    }

    printf("Case #%d: %d %d %d\n", caa, states, (int)round(road_cost),
           (int)round(railroad_cost));
  }
  return 0;
}
