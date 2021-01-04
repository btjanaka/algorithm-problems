// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) components-in-graph
// Title: Components in a Graph
// Link: https://www.hackerrank.com/challenges/components-in-graph/problem
// Idea: Use a union find to figure out which nodes get connected, then count
// the sizes of all the components.
// Difficulty: medium
// Tags: union-find
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct UnionFind {
  vector<int> parent, ranks, sizes;
  UnionFind(int n) : parent(n), ranks(n, 0), sizes(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int i) { return i == parent[i] ? i : (parent[i] = find(parent[i])); }
  void join(int i, int j) {
    int x = find(i), y = find(j);
    if (x != y) {
      if (ranks[x] > ranks[y]) {
        sizes[x] += sizes[y];
        parent[y] = x;
      } else {
        if (ranks[x] == ranks[y]) {
          ++ranks[y];
        }
        parent[x] = y;
        sizes[y] += sizes[x];
      }
    }
  }
};

int main() {
  int n, n2;
  GET(n);
  n2 = 2 * n;

  UnionFind uf(n2);
  for (int e = 0; e < n; ++e) {
    int i, j;
    GET(i);
    GET(j);
    --i;
    --j;
    uf.join(i, j);
  }

  int mx = INT_MIN, mn = INT_MAX;
  for (int i = 0; i < n2; ++i) {
    if (uf.sizes[i] != 1 && uf.parent[i] == i) {
      mx = max(mx, uf.sizes[i]);
      mn = min(mn, uf.sizes[i]);
    }
  }

  cout << mn << " " << mx << endl;

  return 0;
}
