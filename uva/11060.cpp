// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11060
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  string s, a;
  for (int ca = 1; cin >> n; ++ca) {
    // graph input
    unordered_map<string, unordered_set<string>> g;
    unordered_map<string, int> ord;
    unordered_map<string, int> in;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      g[s] = {};
      ord[s] = i;
      in[s] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> s >> a;
      // watch out for duplicate edges in the input
      if (g[s].find(a) == g[s].end()) ++in[a];
      g[s].insert(a);
    }

    // topological sort
    printf("Case #%d: Dilbert should drink beverages in this order:", ca);
    priority_queue<pair<int, string>, vector<pair<int, string>>,
                   greater<pair<int, string>>>
        pq;
    for (auto& x : in) {
      if (x.second == 0) {
        pq.push({ord[x.first], x.first});
      }
    }
    while (!pq.empty()) {
      pair<int, string> cur = pq.top();
      pq.pop();
      printf(" %s", cur.second.c_str());
      for (auto& x : g[cur.second]) {
        --in[x];
        if (in[x] == 0) {
          pq.push({ord[x], x});
        }
      }
    }
    printf(".\n\n");
  }
  return 0;
}
