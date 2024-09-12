// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 399
// Title: Evaluate Division
// Link: https://leetcode.com/problems/evaluate-division/
// Idea: Frame this as a graph problem where you can move around nodes and
// multiply the costs together. E.g. if you have a, b, and c, then moving from a
// to b is a/b, and b to c is b/c, so to get from a to c is a/b * b/c. Once we
// set up this graph, use a traversal algorithm to see if there is a path
// from c to d.
// Difficulty: Medium
// Tags: Graph, BFS, DFS
class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    // Construct graph mapping from numerators to denominators.
    unordered_map<string, vector<pair<string, double>>> g;
    for (int i = 0; i < equations.size(); ++i) {
      string &a = equations[i][0], b = equations[i][1];
      double val = values[i];
      if (g.find(a) == g.end()) g[a] = {};
      if (g.find(b) == g.end()) g[b] = {};
      // Add both a/b and b/a.
      g[a].push_back({b, val});
      g[b].push_back({a, 1.0 / val});
    }

    vector<double> res;

    for (const auto& query : queries) {
      const string &c = query[0], d = query[1];

      // c or d not defined.
      if (g.find(c) == g.end() || g.find(d) == g.end()) {
        res.push_back(-1);
        continue;
      }

      // Use BFS to see if we can find a path between the query's numerator and
      // denominator.
      unordered_set<string> visited;
      queue<pair<string, double>>
          q;  // Stores node and the product along the path.
      bool success = false;
      q.push({c, 1.0});  // Start at c with product of 1.0.
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        const string& node = cur.first;
        double cost = cur.second;

        if (node == d) {
          res.push_back(cost);
          success = true;
          break;
        }

        if (visited.find(node) != visited.end()) continue;
        visited.insert(node);

        for (const auto& next : g[node]) {
          q.push({next.first, next.second * cost});
        }
      }

      if (!success) res.push_back(-1.0);
    }

    return res;
  }
};
