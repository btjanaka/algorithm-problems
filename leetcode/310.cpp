// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 310
// Title: Minimum Height Trees
// Link: https://leetcode.com/problems/minimum-height-trees/
// Idea: Find the diameter of the tree by running two DFS's -- one from any
// starting node to find the node x that is farthest away, then one from the
// node x to find the node y farthest away from it. The path from x to y is the
// longest path (i.e., the "diameter path" of the tree) -- select one or two
// nodes along that path, depending on whether the path has an odd or even
// number of nodes.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  void dfs(int cur, vector<vector<int>>& g, vector<int>& curPath,
           vector<int>& longestPath, vector<bool>& visited, int& n_visited) {
    curPath.push_back(cur);
    visited[cur] = true;
    ++n_visited;

    // Has one neighbor and the neighbor is visited.
    bool isEndLeaf = g[cur].size() == 1 && visited[g[cur][0]];

    if (curPath.size() > longestPath.size() && isEndLeaf) {
      longestPath = curPath;
    }

    for (int next : g[cur]) {
      if (!visited[next]) {
        dfs(next, g, curPath, longestPath, visited, n_visited);
      }
    }

    curPath.pop_back();
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    vector<vector<int>> g(n);
    for (int i = 0; i < edges.size(); ++i) {
      int a = edges[i][0], b = edges[i][1];
      g[a].push_back(b);
      g[b].push_back(a);
    }

    vector<int> longestPath;
    vector<int> curPath;
    vector<bool> visited(n, false);
    int n_visited = 0;
    int start;
    for (int i = 0; i < edges.size(); ++i) {
      if (g[i].size() == 0) {
        start = i;
        break;
      }
    }

    // Compute diameter of the tree. First find the node that is farthest away
    // from any leaf.
    dfs(start, g, curPath, longestPath, visited, n_visited);
    int end = longestPath.back();

    // Then find the node that is farthest from that farthest-away node.
    visited.assign(n, 0);
    n_visited = 0;
    dfs(end, g, curPath, longestPath, visited, n_visited);

    for (int x : longestPath) cout << " " << x;
    cout << endl;

    int pathLength = longestPath.size();
    vector<int> roots;
    if (pathLength % 2 == 0) {
      roots.push_back(longestPath[pathLength / 2]);
      roots.push_back(longestPath[pathLength / 2 - 1]);
    } else {
      roots.push_back(longestPath[pathLength / 2]);
    }
    return roots;
  }
};
