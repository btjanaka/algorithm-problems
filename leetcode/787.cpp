// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 787
// Title: Cheapest Flights Within K Stops
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Idea: Perform a BFS that only goes K layers deep, and if dst is reached
// within that search, you can return its distance.
// Difficulty: medium
// Tags: BFS, graph
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    vector<vector<pair<int, int>>> g(n);
    for (vector<int> f : flights) {
      g[f[0]].push_back({f[1], f[2]});
    }

    int d = -1;
    queue<tuple<int, int, int>> q;
    q.push({src, 0, 0});
    while (!q.empty()) {
      int u, stops, dist;
      tie(u, stops, dist) = q.front();
      q.pop();

      for (pair<int, int> v : g[u]) {
        if (v.first == dst) {
          if (d == -1 || dist + v.second < d) {
            d = dist + v.second;
          }
        } else {
          // Don't add in the node if it exceeds the distance or number of
          // stops.
          if (stops < K && (d == -1 || dist + v.second < d)) {
            q.push({v.first, stops + 1, dist + v.second});
          }
        }
      }
    }

    return d;
  }
};
