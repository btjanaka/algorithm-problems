// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10608
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> rank, p, size;
  int sz(int a) { return size[findSet(a)]; }
  int findSet(int a) { return a == p[a] ? a : (p[a] = findSet(p[a])); }
  bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
  void unionSet(int a, int b) {
    if (!isSameSet(a, b)) {
      int x = findSet(a), y = findSet(b);
      if (rank[x] < rank[y]) {
        p[x] = y;
        size[y] += size[x];
      } else {
        p[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) {
          ++rank[x];
        }
      }
    }
  }
  UnionFind(int n) : rank(n, 0), p(n), size(n, 1) {
    iota(p.begin(), p.end(), 0);
  }
};

int main() {
  int ca;
  GET(ca);
  int n, m;
  while (ca--) {
    GET(n);
    GET(m);
    UnionFind uf(n);
    while (m--) {
      int a, b;
      GET(a);
      GET(b);
      --a;
      --b;
      uf.unionSet(a, b);
    }
    int mx = -1;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, uf.sz(i));
    }
    printf("%d\n", mx);
  }
  return 0;
}
