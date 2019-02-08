// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12442
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int g[50050];
int dp[50050];
int f(int start) {
  if (dp[start] != -1) return dp[start];

  // keep track of nodes that you are visiting in order; then when you reach the
  // cycle (note that there will always be a cycle) set all the ones in the
  // cycle to the same and then go back and keep adding one in the order
  unordered_set<int> visited;
  vector<int> order;
  unordered_map<int, int> node_to_order;

  // searching for cycle - or a child who has already been covered
  int cur = start;
  while (visited.find(cur) == visited.end()) {
    // shortcut
    if (dp[cur] != -1) {
      for (int i = order.size() - 1; i >= 0; --i) {
        dp[order[i]] = dp[cur] + order.size() - i;
      }
      return dp[start];
    }
    order.push_back(cur);
    node_to_order[cur] = order.size() - 1;
    visited.insert(cur);
    cur = g[cur];
  }

  // found cycle, now assign values
  int prev = node_to_order[cur];
  for (int i = prev; i < order.size(); ++i) {
    dp[order[i]] = order.size() - prev;
  }
  for (int i = prev - 1; i >= 0; --i) {
    dp[order[i]] = order.size() - i;
  }

  return dp[start];
}

int main() {
  int ca, u, v;
  int n;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    GET(n);
    for (int i = 0; i < n; ++i) {
      GET(u);
      GET(v);
      g[u] = v;  // EXACTLY 1 of each u
    }

    memset(dp, -1, sizeof(dp));
    int mx = -1;
    int mxi = 0;
    for (int i = 1; i <= n; ++i) {
      if (f(i) > mx) {
        mxi = i;
        mx = f(i);
      }
    }

    printf("Case %d: %d\n", caa, mxi);
  }
  return 0;
}
