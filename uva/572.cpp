// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 572
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

char grid[110][110];
bool visited[110][110];
int m, n;

void bfs(int i, int j) {
  visited[i][j] = true;
  queue<ii> to_visit;
  to_visit.push({i, j});

  while (!to_visit.empty()) {
    int curi = to_visit.front().first;
    int curj = to_visit.front().second;
    to_visit.pop();

    int ni[8] = {curi + 1, curi + 1, curi + 1, curi,
                 curi,     curi - 1, curi - 1, curi - 1};
    int nj[8] = {curj + 1, curj,     curj - 1, curj + 1,
                 curj - 1, curj + 1, curj,     curj - 1};

    for (int k = 0; k < 8; ++k) {
      int r = ni[k];
      int c = nj[k];
      if (r < m && r >= 0 && c < n && c >= 0 && !visited[r][c] &&
          grid[r][c] == '@') {
        visited[r][c] = true;
        to_visit.push({r, c});
      }
    }
  }
}

int main() {
  while (GET(m) && GET(n) && (m || n)) {
    getchar();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        grid[i][j] = getchar();
      }
      getchar();
    }
    memset(visited, false, sizeof(visited));

    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '@' && !visited[i][j]) {
          bfs(i, j);
          ++res;
        }
      }
    }

    printf("%d\n", res);
  }
  return 0;
}
