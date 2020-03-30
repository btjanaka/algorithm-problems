// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) islands3
// Title: Islands
// Link: https://open.kattis.com/problems/islands3
// Idea: Use BFS to find connected components in the grid.
// Difficulty: medium
// Tags: graph, connected-components, breadth-first-search
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int r, c;
char pic[55][55];
bool visited[55][55];

void bfs(int r0, int c0) {
  queue<ii> to_visit;
  to_visit.push({r0, c0});
  visited[r0][c0] = true;
  while (!to_visit.empty()) {
    ii cur = to_visit.front();
    to_visit.pop();
    int i = cur.first, j = cur.second;
    if (i > 0 && (pic[i - 1][j] == 'L' || pic[i - 1][j] == 'C') &&
        !visited[i - 1][j]) {
      to_visit.push({i - 1, j});
      visited[i - 1][j] = true;
    }
    if (j > 0 && (pic[i][j - 1] == 'L' || pic[i][j - 1] == 'C') &&
        !visited[i][j - 1]) {
      to_visit.push({i, j - 1});
      visited[i][j - 1] = true;
    }
    if (i < r - 1 && (pic[i + 1][j] == 'L' || pic[i + 1][j] == 'C') &&
        !visited[i + 1][j]) {
      to_visit.push({i + 1, j});
      visited[i + 1][j] = true;
    }
    if (j < c - 1 && (pic[i][j + 1] == 'L' || pic[i][j + 1] == 'C') &&
        !visited[i][j + 1]) {
      to_visit.push({i, j + 1});
      visited[i][j + 1] = true;
    }
  }
}

int main() {
  while (GET(r) > 0) {
    GET(c);
    for (int i = 0; i < r; ++i) scanf("%s", pic[i]);

    // find connected components
    memset(visited, false, sizeof(visited));
    int comp = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (!visited[i][j] && pic[i][j] == 'L') {
          ++comp;
          bfs(i, j);
        }
      }
    }

    printf("%d\n", comp);
  }
  return 0;
}
