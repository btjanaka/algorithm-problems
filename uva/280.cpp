// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 280
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

bool visited[100];
bool first;

void dfs(int cur, const vector<vector<int>>& graph) {
  if (visited[cur]) return;
  if (first)
    first = false;
  else
    visited[cur] = true;
  for (int i : graph[cur]) {
    dfs(i, graph);
  }
}

int main() {
  int n;
  while (GET(n) && n) {
    vector<vector<int>> graph(n);

    int i;
    while (GET(i) && i) {
      --i;
      int j;
      while (GET(j) && j) {
        --j;
        graph[i].push_back(j);
      }
    }

    int c, start;
    GET(c);
    while (c--) {
      memset(visited, false, sizeof(visited));
      GET(start);
      --start;
      first = true;
      dfs(start, graph);

      vector<int> res;
      for (i = 0; i < n; ++i) {
        if (!visited[i]) {
          res.push_back(i + 1);
        }
      }
      printf("%d", (int)res.size());
      for (int x : res) printf(" %d", x);
      printf("\n");
    }
  }
  return 0;
}
