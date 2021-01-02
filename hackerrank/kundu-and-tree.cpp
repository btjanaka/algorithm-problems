// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) kundu-and-tree
// Title: Kundu and Tree
// Link: https://www.hackerrank.com/challenges/kundu-and-tree/problem
// Idea: First, count up the total number of triplets in the tree. Then,
// subtract the triplets that would have a path connected by only black edges.
// To find such triplets, we use a union find that only keeps track of black
// edges. Each connected component in the union find contains nodes that are
// part of an invalid triplet (see code comments for more).
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
  ll n;
  scanf("%lld", &n);

  // Input n - 1 edges - only add black edges to uf.
  UnionFind uf(n);
  for (int e = 1; e < n; ++e) {
    int i, j;
    char color;
    scanf("%d %d %c", &i, &j, &color);
    if (color == 'b') {
      --i;
      --j;
      uf.join(i, j);
    }
  }

  // Start with the total number of triplets, which fits in long long.
  ll triplets = (n * (n - 1) * (n - 2)) / 6;
  for (int i = 0; i < n; ++i) {
    // Then for each component in uf (this is identified by finding the parent
    // nodes), subtract the number of triplets that would be created with nodes
    // in that component.
    ll size = uf.sizes[i];
    if (uf.parent[i] == i && size > 1) {
      // Triplets created by a pair of nodes in the component along with an
      // external node.
      ll pairs = (size * (size - 1)) / 2;
      triplets -= (n - size) * pairs;

      // Triplets created by a triplet of nodes in the component.
      if (size > 2) {
        triplets -= (size * (size - 1) * (size - 2)) / 6;
      }
    }
  }
  cout << (triplets % 1'000'000'007) << endl;

  return 0;
}
