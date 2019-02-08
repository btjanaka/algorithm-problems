// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 796
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int dfsi;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
set<ii> art;
vector<unordered_set<int>> g;
void dfs(int u) {
  dfs_num[u] = dfs_low[u] = dfsi++;
  for (int v : g[u]) {
    if (dfs_num[v] == -1) {
      parent[v] = u;
      dfs(v);
      // found an articulation bridge/edge - note > not >=
      // if it is >= then there is a back edge from v to u and removing this
      // edge will not do anything
      if (dfs_low[v] > dfs_num[u]) {
        art.insert({min(u, v), max(u, v)});
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (parent[u] != v) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main() {
  int n;
  while (GET(n) > 0) {
    // input
    g.assign(n, {});
    for (int i = 0; i < n; ++i) {
      int u, k, v;
      scanf("%d (%d)", &u, &k);
      for (int j = 0; j < k; ++j) {
        GET(v);
        g[u].insert(v);
        g[v].insert(u);
      }
    }

    // find articulation bridges - note: disregard edge case with root because
    // only care about finding bridges
    dfsi = 0;
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    parent.assign(n, -1);
    art.clear();
    for (int i = 0; i < n; ++i) {
      if (dfs_num[i] == -1) {
        dfs(i);
      }
    }

    // output
    printf("%lu critical links\n", art.size());
    for (const ii& x : art) {
      printf("%d - %d\n", x.first, x.second);
    }
    printf("\n");
  }
  return 0;
}
