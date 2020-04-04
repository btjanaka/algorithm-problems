// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeJam) 2020-qual-parenting-partnering-returns
// Title: Parenting Partnering Returns
// Link:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
// Idea: Build a graph where activities connect iff they overlap. Then check
// whether this graph is bipartite. When the graph is bipartite, that means the
// activities can be split into two sets that do not have any overlap.
// Difficulty: medium
// Tags: bipartite-graph
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

inline bool overlap(ii a, ii b) {
  return !((a.first <= b.first && a.second <= b.first) ||
           (a.first >= b.second && a.second >= b.second));
}

int main() {
  int t;
  cin >> t;
  for (int ca = 1; ca <= t; ++ca) {
    int n;
    cin >> n;
    vector<ii> activities(n);
    for (int i = 0; i < n; ++i)
      cin >> activities[i].first >> activities[i].second;

    // Build graph based on activities that overlap.
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (overlap(activities[i], activities[j])) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }

    // Bipartite graph check with BFS and bicoloring -- colors are 'C' and 'J'.
    string status(n, '0');
    bool ok = true;
    queue<int> q;  // Avoid re-allocating.
    for (int start = 0; start < n; ++start) {
      if (status[start] == '0') {
        q.push(start);
        status[start] = 'C';
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int v : g[u]) {
            if (status[v] == '0') {
              status[v] = status[u] == 'C' ? 'J' : 'C';
              q.push(v);
            } else if (status[v] == status[u]) {
              ok = false;
              goto not_ok;  // Nested loops...
            }
          }
        }
      }
    }

  not_ok:

    cout << "Case #" << ca << ": ";
    if (ok) {
      cout << status;
    } else {
      cout << "IMPOSSIBLE";
    }
    cout << "\n";
  }

  return 0;
}
