// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10369
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
  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  bool join(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
      }
      return true;
    }
    return false;
  }
};

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int s, p;
    GET(s);
    GET(p);
    vector<ii> coords;
    for (int i = 0; i < p; ++i) {
      int x, y;
      GET(x);
      GET(y);
      coords.push_back({x, y});
    }

    vector<pair<double, ii>> edges;
    for (int i = 0; i < p; ++i) {
      for (int j = i + 1; j < p; ++j) {
        double dx = coords[i].first - coords[j].first;
        double dy = coords[i].second - coords[j].second;
        double d = sqrt(dx * dx + dy * dy);
        edges.push_back({d, {i, j}});
      }
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(p);
    vector<bool> used(edges.size());
    for (int i = 0; i < edges.size(); ++i) {
      used[i] = uf.join(edges[i].second.first, edges[i].second.second);
    }

    unordered_set<int> has_s;
    bool printed = false;
    for (int i = edges.size() - 1; i >= 0; --i) {
      if (used[i]) {
        if (s > 1) {
          --s;
        } else {
          printf("%.2lf\n", edges[i].first);
          printed = true;
          break;
        }
      }
    }
    if (!printed) printf("0.00\n");
  }
  return 0;
}
