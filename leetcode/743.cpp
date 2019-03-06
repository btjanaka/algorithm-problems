// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 743
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    --K;
    vector<vector<pair<int, int>>> g(N);
    for (int i = 0; i < times.size(); ++i) {
      int u = times[i][0], v = times[i][1], w = times[i][2];
      --u;
      --v;
      g[u].push_back({v, w});
    }

    vector<int> dist(N, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, K});
    dist[K] = 0;
    while (!pq.empty()) {
      pair<int, int> cur = pq.top();
      pq.pop();
      int d = cur.first, u = cur.second;
      if (d > dist[u] && dist[u] != -1) continue;
      for (pair<int, int> child : g[u]) {
        int v = child.first, w = child.second;
        if (dist[u] + w < dist[v] || dist[v] == -1) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }

    if (any_of(dist.begin(), dist.end(), [](int x) { return x == -1; })) {
      return -1;
    } else {
      return *max_element(dist.begin(), dist.end());
    }
  }
};
