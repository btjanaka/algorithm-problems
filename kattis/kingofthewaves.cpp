// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) kingofthewaves
// Title: King of the Waves
// Link: https://open.kattis.com/problems/kingofthewaves
// Idea: If everything is reachable from 0, we can win (where we represent the
// graph as having an edge A->B if A beats B). We can then carry out a
// postorder DFS to solve the problem.
// Difficulty: medium
// Tags: graph, depth-first-search
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

void dfs(int cur, int n, vector<string>& g, vector<int>& res,
         vector<bool>& visited) {
  if (visited[cur]) return;
  visited[cur] = true;

  for (int i = 0; i < n; ++i) {
    if (g[cur][i] == '1') {
      dfs(i, n, g, res, visited);
    }
  }

  res.push_back(cur);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<string> g(n);
    cin.get();
    for (int i = 0; i < n; ++i) {
      cin >> g[i];
    }

    vector<int> res;
    vector<bool> visited(n, false);
    dfs(0, n, g, res, visited);
    if (res.size() == n) {
      for (int i = 0; i < n; ++i) {
        printf("%d%c", res[i], i == n - 1 ? '\n' : ' ');
      }
    } else {
      printf("impossible\n");
    }
  }
  return 0;
}
