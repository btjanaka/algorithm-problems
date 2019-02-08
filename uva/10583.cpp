// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10583
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> p, rank;
  UnionFind(int n) : p(n), rank(n, 0) { iota(p.begin(), p.end(), 0); }
  int find(int i) { return p[i] == i ? i : (p[i] = find(p[i])); }
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
  int countp() {
    unordered_set<int> ps;
    for (int i = 0; i < p.size(); ++i) ps.insert(find(i));
    return (int)ps.size();
  }
};

int main() {
  int n, m;
  for (int ca = 1; GET(n) && GET(m) && (n || m); ++ca) {
    int a, b;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      GET(a);
      GET(b);
      uf.join(a - 1, b - 1);
    }
    printf("Case %d: %d\n", ca, uf.countp());
  }
  return 0;
}
