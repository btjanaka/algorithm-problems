// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 793
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> p, rank;
  UnionFind(int N) : rank(N, 0), p(N) { iota(p.begin(), p.end(), 0); }
  int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int suc = 0;
    int usuc = 0;

    int n;
    GET(n);
    getchar();
    UnionFind uf(n);
    char buf[100];
    while (fgets(buf, 100, stdin) && buf[0] != '\n') {
      char ch;
      int c1, c2;
      sscanf(buf, " %c %d %d", &ch, &c1, &c2);
      --c1;
      --c2;
      if (ch == 'c') {
        uf.unionSet(c1, c2);
      } else {
        if (uf.isSameSet(c1, c2)) {
          ++suc;
        } else {
          ++usuc;
        }
      }
    }

    printf("%d,%d\n", suc, usuc);
    if (ca != 0) printf("\n");
  }
  return 0;
}
