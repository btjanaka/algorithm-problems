// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 685
// Title: Redundant Connection II
// Link: https://leetcode.com/problems/redundant-connection-ii/
// Idea: There's two main possibilities -- when there's a cycle, and when
// there's a node with two parents. But there's also a ton of edge cases, such
// as when a node with two parents is part of a cycle, or when one of the two
// parents of a node is the root... It's more of a tedious than hard problem
// IMO.
// Difficulty: medium
// Tags: implementation, graph
class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<int>> parents(n + 1);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      parents[v].push_back(u);
    }

    // 1. Check if there is a cycle with (iterative) DFS.
    vector<vector<pair<int, int>>> graph(
        n +
        1);  // Stores the neighbor and what order the edge was in the input.
    for (int i = 0; i < n; ++i) {
      int u = edges[i][0], v = edges[i][1];
      graph[u].push_back({v, i});
    }

    vector<int> status(n + 1);  // 1 is visited, 2 is on path
    stack<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
      if (status[i]) continue;

      bool found_cycle = false;
      s.push({i, -1});
      status[i] = 1;
      while (!s.empty()) {
        int cur, _;
        tie(cur, _) = s.top();
        if (status[cur] == 2) {
          status[cur] = 1;
          s.pop();
        } else if (status[cur] == 1) {
          status[cur] = 2;
          for (const auto& nbor : graph[cur]) {
            int v, ord;
            tie(v, ord) = nbor;
            if (status[v] == 2) {
              s.push({v, ord});
              found_cycle = true;
              break;
            } else if (!status[v]) {
              status[v] = 1;
              s.push({v, ord});
            }
          }
        }
        if (found_cycle) break;
      }

      if (found_cycle) {
        // Find the nodes on the current path by popping the cycle off the
        // stack.
        vector<pair<int, int>> path;
        path.push_back(s.top());
        s.pop();
        while (s.top().first != path[0].first) {
          if (status[s.top().first] == 2) path.push_back(s.top());
          s.pop();
        }

        // Find the edge with the highest order.
        int mx_order = -1;
        vector<int> edge;
        for (int i = 0; i < path.size() - 1; ++i) {
          if (path[i].second > mx_order) {
            mx_order = path[i].second;
            edge = {path[i + 1].first, path[i].first};
          }

          // The node in the cycle may also have two parents, in which case the
          // edge to it must be removed.
          if (parents[path[i].first].size() == 2) {
            mx_order = INT_MAX;
            edge = {path[i + 1].first, path[i].first};
          }
        }

        return edge;
      }
    }

    // 2. Check if any node has two parents.
    //    (Do this after cycle check because nodes in the cycle may have two
    //    parents).
    for (int i = 1; i <= n; ++i) {
      if (parents[i].size() == 2) {
        int p = parents[i][1];  // Prefer the parent that was added last.
        // But if the parent has no parents, it is the root. If the root has
        // only one child, this edge must be maintained.
        if (parents[p].size() == 0 && graph[p].size() == 1) p = parents[i][0];
        return {p, i};
      }
    }

    return {};  // Should be unreachable.
  }
};
