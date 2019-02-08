// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11094
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

char g[25][25];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int m, n, r0, c0;
bool visited[25][25];
char landletter;
int dfs(int rcur, int ccur) {
  if (visited[rcur][ccur]) return 0;
  visited[rcur][ccur] = true;

  int count = 1;
  for (int i = 0; i < 4; ++i) {
    int r2 = rcur + dr[i], c2 = ccur + dc[i];
    if (c2 == n) c2 = 0;
    if (c2 < 0) c2 = n - 1;
    if (!(r2 < 0 || r2 >= m || c2 < 0 || c2 >= n || g[r2][c2] != landletter)) {
      count += dfs(r2, c2);
    }
  }
  return count;
}

int main() {
  while (GET(m) > 0) {
    GET(n);
    getchar();
    for (int i = 0; i < m; ++i) {
      fgets(g[i], 25, stdin);
    }
    GET(r0);
    GET(c0);

    int mx = 0;
    memset(visited, false, sizeof(visited));
    landletter = g[r0][c0];
    dfs(r0, c0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && g[i][j] == landletter) mx = max(mx, dfs(i, j));
      }
    }

    printf("%d\n", mx);
  }
  return 0;
}
