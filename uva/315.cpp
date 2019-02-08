// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 315
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int dfsi;
int root_children;
void articulation(int u, vector<bool>& art, vector<int>& dfs_parent,
                  vector<int>& dfs_num, vector<int>& dfs_low,
                  vector<unordered_set<int>>& g) {
  dfs_num[u] = dfs_low[u] = dfsi++;
  for (int v : g[u]) {
    if (dfs_num[v] == -1) {
      dfs_parent[v] = u;
      if (u == 1) ++root_children;
      articulation(v, art, dfs_parent, dfs_num, dfs_low, g);
      if (dfs_low[v] >= dfs_num[u]) {
        art[u] = true;
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int n;
  while (getline(cin, s)) {
    // input
    stringstream ss(s);
    ss >> n;
    if (n == 0) break;

    vector<unordered_set<int>> g(n + 1);
    while (true) {
      int u;
      getline(cin, s);
      stringstream ss2(s);
      ss2 >> u;
      if (u == 0) {
        break;
      } else {
        int v;
        while (ss2 >> v) {
          g[u].insert(v);
          g[v].insert(u);
        }
      }
    }

    dfsi = 0;
    root_children = 0;
    vector<bool> art(n + 1, false);
    vector<int> dfs_parent(n + 1, -1);
    vector<int> dfs_num(n + 1, -1);
    vector<int> dfs_low(n + 1, -1);
    articulation(1, art, dfs_parent, dfs_num, dfs_low, g);
    art[1] = root_children > 1;

    printf("%d\n", accumulate(art.begin() + 1, art.end(), 0));
  }

  return 0;
}
