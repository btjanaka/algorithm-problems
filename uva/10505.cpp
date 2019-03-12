// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10505
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int ca;
  GET(ca);

  while (ca--) {
    // input
    int n;
    GET(n);
    unordered_map<int, unordered_set<int>> g;
    for (int i = 1; i <= n; ++i) g[i] = {};
    for (int a = 1; a <= n; ++a) {
      int p;
      GET(p);
      for (int i = 0; i < p; ++i) {
        int b;
        GET(b);
        if (b > n) continue;
        g[a].insert(b);
        g[b].insert(a);
      }
    }

    // bipartite graph check
    unordered_map<int, int> visited;
    for (const auto& x : g) visited[x.first] = -1;
    int tot = 0;
    for (int start = 1; start <= n; ++start) {
      if (visited[start] == -1) {
        queue<int> q;
        q.push(start);
        visited[start] = 0;
        bool ok = true;
        int zero = 0, one = 0;

        while (!q.empty()) {
          int u = q.front();
          q.pop();

          if (!ok) {
            visited[u] = 0;
            continue;
          }

          if (u >= 1 && u <= n) {
            if (visited[u] == 0) {
              ++zero;
            } else {
              ++one;
            }
          }

          for (int v : g[u]) {
            if (visited[v] == -1) {
              visited[v] = 1 - visited[u];
              q.push(v);
            } else if (visited[v] == visited[u]) {
              ok = false;
              q.push(v);
            }
          }
        }

        if (ok) tot += max(zero, one);
      }
    }

    printf("%d\n", tot);
  }
  return 0;
}
