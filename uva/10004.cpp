// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10004
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int n, l;

int main() {
  int u, v;
  while (GET(n) && n) {
    GET(l);
    vector<unordered_set<int>> g(n);
    for (int i = 0; i < l; ++i) {
      GET(u);
      GET(v);
      g[u].insert(v);
      g[v].insert(u);
    }

    // bicolor using bfs
    bool ok = true;
    vector<int> colors(n, INT_MAX);
    queue<int> q;
    q.push(0);
    colors[0] = 0;
    while (!q.empty() && ok) {
      int cur = q.front();
      q.pop();
      for (int child : g[cur]) {
        if (colors[child] == INT_MAX) {
          colors[child] = 1 - colors[cur];
          q.push(child);
        } else if (colors[child] == colors[cur]) {
          ok = false;
          break;
        }
      }
    }

    printf(ok ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
  }
  return 0;
}
