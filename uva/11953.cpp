// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11953
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int n;
char g[110][110];
bool visited[110][110];
bool isship(char ch) { return ch == '@' || ch == 'x'; }
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool dfs(int r, int c) {
  if (visited[r][c]) return false;
  visited[r][c] = true;

  bool ok = g[r][c] == 'x';

  for (int i = 0; i < 4; ++i) {
    int r2 = r + dr[i], c2 = c + dc[i];
    if (!(r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || g[r2][c2] == '.')) {
      ok |= dfs(r2, c2);
    }
  }

  return ok;
}

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    GET(n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", g[i]);
    }

    memset(visited, false, sizeof(visited));
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && isship(g[i][j])) {
          res += dfs(i, j);
        }
      }
    }

    printf("Case %d: %d\n", caa, res);
  }
  return 0;
}
