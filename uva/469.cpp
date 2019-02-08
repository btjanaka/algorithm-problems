// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 469
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int n, m;
string g[110];
bool visited[110][110];
int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int bfs(int startr, int startc) {
  int tot = 0;
  queue<ii> to_visit;
  to_visit.push({startr, startc});
  visited[startr][startc] = true;
  while (!to_visit.empty()) {
    ++tot;
    ii cur = to_visit.front();
    to_visit.pop();
    for (int i = 0; i < 8; ++i) {
      int r2 = cur.first + dr[i], c2 = cur.second + dc[i];
      if (!(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m || visited[r2][c2] ||
            g[r2][c2] == 'L')) {
        visited[r2][c2] = true;
        to_visit.push({r2, c2});
      }
    }
  }
  return tot;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  string s;
  cin >> ca;
  getline(cin, s);
  getline(cin, s);
  while (ca--) {
    n = 0;
    while (getline(cin, s)) {
      if (s == "") {
        break;
      } else if (s[0] == 'L' || s[0] == 'W') {
        // get grid
        g[n] = s;
        ++n;
        m = (int)s.size();
      } else {
        // handle queries
        int r, c;
        sscanf(s.c_str(), "%d %d", &r, &c);
        --r;
        --c;
        memset(visited, false, sizeof(visited));
        printf("%d\n", bfs(r, c));
      }
    }
    if (ca) printf("\n");
  }
  return 0;
}
