// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) similarpair
// Title: Similar Pair
// Link: https://www.hackerrank.com/challenges/similarpair/problem
// Idea: Use a Fenwick Tree to keep track of the items we have previously seen.
// Then perform a DFS while using the Fenwick Tree to keep track of the items in
// the current ancestors. We can query the tree to find the similar pairs for
// the current node.
// Difficulty: hard
// Tags: fenwick-tree, tree, graph
#include <bits/stdc++.h>
using namespace std;

// Made 0-indexed by adding 1 to the index in rsq(int b) and adjust()
struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int lsone(int i) { return i & (-i); }
  int rsq(int b) {
    if (b < 0) return 0;
    ++b;
    int sum = 0;
    for (; b; b -= lsone(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) {
    // no need to add here since rsq(int b) already adds 1
    return rsq(b) - (a == 0 ? 0 : rsq(a - 1));
  }
  void adjust(int k, int v) {
    ++k;
    for (; k < (int)ft.size(); k += lsone(k)) ft[k] += v;
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  // Input the graph
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  vector<int> in_deg(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    ++in_deg[v];
  }

  // Find the root
  int root = 0;
  for (int i = 1; i <= n; ++i) {
    if (in_deg[i] == 0) {
      root = i;
      break;
    }
  }

  // Use a FenwickTree to keep track of counts of previously seen nodes while
  // performing an iterative DFS.
  long long similar = 0;
  FenwickTree prev(n + 1);
  stack<int> s;
  s.push(root);
  vector<bool> visited(n + 1);
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (!visited[u]) {
      // If u has not been visited, we push it back onto the stack
      // along with its children. We also add on the number of similar pairs.
      visited[u] = true;
      similar += prev.rsq(max(u - k, 0), min(u + k, n));
      s.push(u);
      prev.adjust(u, 1);
      for (int v : g[u]) s.push(v);
    } else {
      // If u has already been visited, its children are done and we
      // can remove it from prev.
      prev.adjust(u, -1);
    }
  }

  cout << similar << endl;

  return 0;
}
