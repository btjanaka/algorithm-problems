// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) bfsshortreach
// Title: Breadth First Search: Shortest Reach
// Link: https://www.hackerrank.com/challenges/bfsshortreach/problem
// Idea: Follow the given instructions.
// Difficulty: easy
// Tags: graph, breadth-first-search
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
    int n, m;
    GET(n);
    GET(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      GET(u);
      GET(v);
      --u;
      --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int s;
    GET(s);
    --s;

    vector<bool> visited(n, false);
    vector<int> dist(n, -1);
    queue<ii> q;
    q.push({s, 0});
    while (!q.empty()) {
      ii cur = q.front();
      q.pop();
      int u = cur.first, d = cur.second;
      dist[u] = d * 6;
      for (int v : g[u]) {
        if (!visited[v]) {
          q.push({v, d + 1});
          visited[v] = true;
        }
      }
    }

    bool first = true;
    for (int i = 0; i < n; ++i) {
      if (i == s) continue;
      if (first) {
        first = false;
      } else {
        printf(" ");
      }
      printf("%d", dist[i]);
    }
    printf("\n");
  }
  return 0;
}
