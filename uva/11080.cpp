// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11080
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

bool ok;            // global :D
vector<int> color;  // color of the nodes - INT_MAX means unassigned
int bfs(int start, vector<unordered_set<int>>& g) {
  int tot = 0;
  int colored = 0;
  color[start] = 0;
  queue<int> q;
  q.push(start);

  // for dealing with self loops
  bool must_favor_colored = false;
  bool must_favor_noncolored = false;

  // heavily modified bipartite
  while (!q.empty() && ok) {
    ++tot;
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (u == v) {
        // major case: self-loops - deal with it by saying that this node HAS to
        // have a guard
        if (color[u] == 0) {
          must_favor_noncolored = true;
        } else {
          must_favor_colored = true;
        }
        if (must_favor_colored && must_favor_noncolored) {
          ok = false;
          return INT_MIN;
        }
      } else if (color[v] == INT_MAX) {
        color[v] = 1 - color[u];
        colored += color[v];
        q.push(v);
      } else if (color[v] == color[u]) {
        ok = false;
        return INT_MIN;
      }
    }
  }

  if (must_favor_colored) return colored;
  if (must_favor_noncolored) return tot - colored;
  if (tot == 1) return 1;  // edge case: 1 node in this component
  return min(colored, tot - colored);
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    // input
    int v, e;
    GET(v);
    GET(e);
    vector<unordered_set<int>> g(v);
    for (int i = 0; i < e; ++i) {
      int f, t;
      GET(f);
      GET(t);
      g[f].insert(t);
      g[t].insert(f);
    }

    // bipartite graph check - but have to go through all vertices because it is
    // possible to have multiple components
    int res = 0;
    ok = true;
    color.assign(v, INT_MAX);
    for (int i = 0; ok && i < v; ++i) {
      // if unvisited
      if (color[i] == INT_MAX) {
        res += bfs(i, g);
      }
    }

    printf("%d\n", ok ? res : -1);
  }
  return 0;
}
