// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) merging-communities
// Title: Merging Communities
// Link: https://www.hackerrank.com/challenges/merging-communities/problem
// Idea: Use a union-find data structure to represent the communities.
// Difficulty: medium
// Tags: union-find
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> size, rank, p;
  UnionFind(int n) : size(n, 1), rank(n, 0), p(n) {
    iota(p.begin(), p.end(), 0);
  }

  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }

  void join(int i, int j) {
    int x = find(i), y = find(j);
    if (x != y) {
      if (rank[x] > rank[y]) {
        p[y] = x;
        size[x] += size[y];
      } else {
        if (rank[x] == rank[y]) {
          ++rank[y];
        }
        p[x] = y;
        size[y] += size[x];
      }
    }
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, q, i, j;
  string cmd;
  cin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    cin >> cmd;
    if (cmd == "Q") {
      cin >> i;
      cout << uf.size[uf.find(i - 1)] << "\n";
    } else {
      cin >> i >> j;
      uf.join(i - 1, j - 1);
    }
  }
  return 0;
}
