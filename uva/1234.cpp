// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1234
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> p, rank;
  UnionFind(int n) : p(n), rank(n, 0) { iota(p.begin(), p.end(), 0); }
  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  void join(int i, int j) {
    if (!same(i, j)) {
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
  while (ca--) {
    int n, m;
    GET(n);
    GET(m);
    vector<pair<int, ii>> edges;
    for (int i = 0; i < m; ++i) {
      int u, v, c;
      GET(u);
      GET(v);
      --u;
      --v;
      GET(c);
      edges.push_back({c, {u, v}});
    }
    sort(edges.begin(), edges.end());

    // Calculate the maximum spanning tree - the remaining edges need cameras
    // because they are the places where the loops close
    UnionFind uf(n);
    int cost = 0;
    for (int i = edges.size() - 1; i >= 0; --i) {
      int u = edges[i].second.first, v = edges[i].second.second,
          c = edges[i].first;
      if (uf.same(u, v)) {
        cost += c;
      } else {
        uf.join(u, v);
      }
    }

    printf("%d\n", cost);
  }
  return 0;
}
