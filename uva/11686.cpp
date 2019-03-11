// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11686
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int n, m;
  while (GET(n) && GET(m) && (n || m)) {
    // input
    vector<unordered_set<int>> g(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; ++i) {
      int a, b;
      GET(a);
      GET(b);
      if (g[a].find(b) == g[a].end()) {
        g[a].insert(b);
        ++in[b];
      }
    }

    // topo sort
    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; ++i) {
      if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      order.push_back(u);
      for (int v : g[u]) {
        --in[v];
        if (in[v] == 0) q.push(v);
      }
    }

    // output
    if (order.size() == n) {
      for (int u : order) printf("%d\n", u);
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
