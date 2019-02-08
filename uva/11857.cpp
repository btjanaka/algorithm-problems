// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11572
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> size, p, rank;
  UnionFind(int n) : size(n, 1), p(n), rank(n, 1) {
    iota(p.begin(), p.end(), 0);
  }

  int find(int u) { return u == p[u] ? p[u] : (p[u] = find(p[u])); }
  bool same(int u, int v) { return find(u) == find(v); }
  void join(int u, int v) {
    if (!same(u, v)) {
      int x = find(u), y = find(v);
      if (rank[x] < rank[y]) {
        p[x] = y;
        size[y] += size[x];
      } else {
        p[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) ++rank[x];
      }
    }
  }
};

int main() {
  int cit, roa;
  while (GET(cit) && GET(roa) && (cit || roa)) {
    vector<vector<int>> edges;
    for (int i = 0; i < roa; ++i) {
      int w, u, v;
      GET(u);
      GET(v);
      GET(w);
      edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(cit);
    int mx = 0;
    for (int i = 0; i < edges.size(); ++i) {
      int w = edges[i][0], u = edges[i][1], v = edges[i][2];
      if (!uf.same(u, v)) {
        uf.join(u, v);
        mx = max(w, mx);
      }
    }

    if (uf.size[uf.find(0)] != cit) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d\n", mx);
    }
  }
  return 0;
}
