// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 684
// Title: Redundant Connection
// Link: https://leetcode.com/problems/redundant-connection/
// Idea: Attempt to construct the MST with Kruskal's algorithm. The first edge
// that can't be added is the bad edge. This finds the last bad edge because all
// the edges that can be added are added.
// Difficulty: medium
// Tags: mst, graph
struct UnionFind {
  vector<int> rank, p;
  UnionFind(int n) : rank(n, 0), p(n) { iota(p.begin(), p.end(), 0); }
  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }
  bool same(int i, int j) { return find(i) == find(j); }
  bool join(int i, int j) {
    if (!same(i, j)) {
      int x = p[i], y = p[j];
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
          ++rank[y];
        }
      }
      return true;
    }
    return false;
  }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    // MST needs n - 1 edges; |edges| will have n items; keep in mind nodes are
    // 1-indexed
    UnionFind uf(edges.size() + 1);
    for (const auto& edge : edges) {
      if (!uf.join(edge[0], edge[1])) return edge;
    }
    return {};  // Should be unreachable.
  }
};
