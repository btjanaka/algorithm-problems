// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 908
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> p, rank;
  UnionFind(int n) : p(n), rank(n, 1) { iota(p.begin(), p.end(), 0); }

  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  void join(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
          ++rank[y];
        }
      }
    }
  }
};

int main() {
  int n;
  int u, v, w;
  int k, m;
  bool first = true;
  while (GET(n) > 0) {
    if (first)
      first = false;
    else
      printf("\n");

    // calc original cost
    int t = n - 1;
    int orig = 0;
    for (int i = 0; i < t; ++i) {
      GET(u);
      GET(v);
      GET(w);
      orig += w;
    }

    // read in edges
    vector<vector<int>> edges;
    GET(k);
    for (int i = 0; i < k; ++i) {
      GET(u);
      GET(v);
      GET(w);
      --u;
      --v;
      edges.push_back({w, u, v});
    }
    GET(m);
    for (int i = 0; i < m; ++i) {
      GET(u);
      GET(v);
      GET(w);
      --u;
      --v;
      edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    // kruskal to get new cost
    UnionFind uf(n);
    int tot = 0;
    for (int i = 0; i < edges.size(); ++i) {
      u = edges[i][1];
      v = edges[i][2];
      w = edges[i][0];
      if (!uf.same(u, v)) {
        uf.join(u, v);
        tot += w;
      }
    }

    // output
    printf("%d\n%d\n", orig, tot);
  }
  return 0;
}
