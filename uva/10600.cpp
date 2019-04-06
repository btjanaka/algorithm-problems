// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10600
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
  int ca;
  GET(ca);
  while (ca--) {
    int n, m;
    int a, b, c;
    bool use;
    GET(n);
    GET(m);
    vector<tuple<int, int, int, bool>> edges;
    for (int i = 0; i < m; ++i) {
      GET(a);
      GET(b);
      GET(c);
      --a;
      --b;
      edges.push_back(make_tuple(c, a, b, true));
    }
    sort(edges.begin(), edges.end());

    // initial MST
    UnionFind uf(n);
    vector<bool> mst(m, false);
    int min_cost = 0;
    for (int i = 0; i < m; ++i) {
      tie(c, a, b, use) = edges[i];
      if (!uf.same(a, b)) {
        uf.join(a, b);
        min_cost += c;
        mst[i] = true;
      }
    }

    // find second best MST
    int min_cost2 = INT_MAX;
    vector<int> skip;
    for (int i = 0; i < m; ++i)
      if (mst[i]) skip.push_back(i);
    for (int s : skip) {
      get<3>(edges[s]) = false;
      UnionFind uf2(n);
      int cost = 0;
      for (int i = 0; i < m; ++i) {
        tie(c, a, b, use) = edges[i];
        if (use && !uf2.same(a, b)) {
          uf2.join(a, b);
          cost += c;
        }
      }
      bool ok = true;
      for (int i = 1; i < n; ++i) {
        ok &= uf2.same(i, 0);
      }
      if (ok) min_cost2 = min(min_cost2, cost);
      get<3>(edges[s]) = true;
    }

    printf("%d %d\n", min_cost, min_cost2);
  }
  return 0;
}
