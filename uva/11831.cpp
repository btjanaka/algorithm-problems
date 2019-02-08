// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11831
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

char grid[110][110];
bool visited[110][110];
char ins[50050];

int main() {
  int n, m, s;
  while (GET(n) && GET(m) && GET(s) && (n || m || s)) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i]);
    }
    scanf("%s", ins);

    // find initial pos
    int r, c, dir;
    unordered_map<char, int> dirs = {{'N', 0}, {'S', 2}, {'L', 1}, {'O', 3}};
    bool init = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dirs.find(grid[i][j]) != dirs.end()) {
          r = i;
          c = j;
          dir = dirs[grid[i][j]];
          init = true;
        }
      }
      if (init) break;
    }

    // N, E, S, W
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // run instructions
    int tot = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < s; ++i) {
      switch (ins[i]) {
        case 'D':
          dir = (dir + 1) % 4;
          break;
        case 'E':
          dir = dir == 0 ? 3 : dir - 1;
          break;
        case 'F':
          int r2 = r + dr[dir];
          int c2 = c + dc[dir];
          if (!(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m ||
                grid[r2][c2] == '#')) {
            r = r2;
            c = c2;
            if (grid[r][c] == '*' && !visited[r][c]) {
              ++tot;
            }
            visited[r][c] = true;
          }
          break;
      }
    }

    printf("%d\n", tot);
  }
  return 0;
}
