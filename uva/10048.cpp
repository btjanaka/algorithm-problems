// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10048
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

struct edge {
  int c1, c2, d;
  bool operator<(const edge& rhs) { return d < rhs.d; }
};

// returns max edge cost along path from cur to tgt
pair<int, bool> dfs(const vector<vector<ii>>& g, int cur, int tgt,
                    vector<bool>& visited) {
  visited[cur] = true;
  if (cur == tgt) {
    return {INT_MIN, true};
  }

  bool found = false;
  int mx = INT_MIN;
  for (ii v : g[cur]) {
    if (visited[v.first]) continue;
    pair<int, bool> next = dfs(g, v.first, tgt, visited);
    if (next.second) {
      found = true;
      mx = max(v.second, next.first);
      break;
    }
  }

  return {mx, found};
}

int main() {
  int c, s, q;
  bool first = true;
  for (int ca = 1; GET(c) && GET(s) && GET(q) && (c || s || q); ++ca) {
    vector<edge> edges;
    for (int i = 0; i < s; ++i) {
      edge e;
      GET(e.c1);
      GET(e.c2);
      GET(e.d);
      edges.push_back(e);
    }
    sort(edges.begin(), edges.end());

    if (first)
      first = false;
    else
      printf("\n");
    printf("Case #%d\n", ca);

    // minimum spanning tree with Kruskal's
    UnionFind uf(c + 1);
    vector<edge> used;
    for (int i = 0; i < edges.size(); ++i) {
      if (uf.join(edges[i].c1, edges[i].c2)) {
        used.push_back(edges[i]);
      }
    }

    vector<vector<ii>> g(c + 1);
    for (edge e : used) {
      g[e.c1].push_back({e.c2, e.d});
      g[e.c2].push_back({e.c1, e.d});
    }

    // take in each query and find max edge between them
    for (int _ = 0; _ < q; ++_) {
      int c1, c2;
      GET(c1);
      GET(c2);
      vector<bool> visited(c + 1, false);
      pair<int, bool> cost = dfs(g, c1, c2, visited);
      if (!cost.second) {
        printf("no path\n");
      } else {
        printf("%d\n", cost.first);
      }
    }
  }
  return 0;
}
