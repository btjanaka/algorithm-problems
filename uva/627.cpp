// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 627
// Title: The Net
// Link:
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=568
// Idea: BFS while keeping track of parents. Input was a pain in the butt.
// Difficulty: Medium
// Tags:
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);

  int n, m;
  while (GET(n) != EOF) {
    vector<vector<int>> g(n + 1);  // Index 0 is ignored.

    // Apparently stringstream is essential to this problem's input.
    char garbage;
    string line;
    for (int i = 0; i < n; ++i) {
      int from;
      cin >> from;
      getline(cin, line);
      stringstream ss(line);
      int to;
      while (ss >> garbage >> to) g[from].push_back(to);
    }

    // Print the graph.
    // for (int i = 1; i <= n; ++i) {
    //   printf("%d:", i);
    //   for (int j = 0; j < g[i].size(); ++j) {
    //     printf(" %d", g[i][j]);
    //   }
    //   printf("\n");
    // }

    printf("-----\n");

    GET(m);
    for (int i = 0; i < m; ++i) {
      int start, end;
      GET(start);
      GET(end);

      if (start == end) {
        printf("%d\n", start);
        continue;
      }

      // BFS from start.
      queue<int> q;
      vector<bool> visited(n + 1);
      vector<int> p(n + 1, -1);
      q.push(start);
      visited[start] = true;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : g[cur]) {
          if (!visited[next]) {
            q.push(next);
            visited[next] = true;
            p[next] = cur;
          }
        }
      }

      // Print path.
      if (p[end] != -1) {
        vector<int> path;
        int cur = end;
        while (cur != start) {
          path.push_back(cur);
          cur = p[cur];
        }
        path.push_back(start);

        for (int i = path.size() - 1; i >= 0; --i) {
          printf("%d", path[i]);
          if (i == 0) {
            printf("\n");
          } else {
            printf(" ");
          }
        }
      } else {
        printf("connection impossible\n");
      }
    }
  }

  return 0;
}
