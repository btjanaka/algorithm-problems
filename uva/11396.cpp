// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11396
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int v;
  while (GET(v) && v) {
    bool ok = true;

    // input
    vector<unordered_set<int>> g(v + 1);
    int a, b;
    while (GET(a) && GET(b) && (a || b)) {
      g[a].insert(b);
      g[b].insert(a);
    }

    // bipartite check
    vector<int> color(v + 1, INT_MAX);
    for (int i = 1; i <= v && ok; ++i) {
      if (color[i] == INT_MAX) {
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while (!q.empty() && ok) {
          int cur = q.front();
          q.pop();
          for (int ch : g[cur]) {
            if (color[ch] == INT_MAX) {
              color[ch] = 1 - color[cur];
              q.push(ch);
            } else if (color[ch] == color[cur]) {
              ok = false;
              break;
            }
          }
        }
      }
    }

    printf(ok ? "YES\n" : "NO\n");
  }
  return 0;
}
