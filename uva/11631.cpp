// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11631
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
  int m, n;
  while (GET(m) && GET(n) && (m || n)) {
    int tot = 0;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i) {
      int x, y, z;
      GET(x);
      GET(y);
      GET(z);
      tot += z;
      edges.push_back(make_tuple(z, x, y));
    }
    sort(edges.begin(), edges.end());

    int cost = 0;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      if (uf.join(get<1>(edges[i]), get<2>(edges[i]))) {
        cost += get<0>(edges[i]);
      }
    }

    printf("%d\n", tot - cost);
  }
  return 0;
}
