// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 929
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int g[1010][1010];
int dist[1010][1010];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, m;
    GET(n);
    GET(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        GET(g[i][j]);
      }
    }

    // d, r, c
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({g[0][0], 0, 0});
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) dist[i][j] = INT_MAX;
    dist[0][0] = g[0][0];

    while (!pq.empty()) {
      vector<int> cur = pq.top();
      pq.pop();
      int d = cur[0], r = cur[1], c = cur[2];
      // printf("%d %d %d\n", d, r, c);
      if (dist[r][c] < d) continue;
      for (int i = 0; i < 4; ++i) {
        int r2 = r + dr[i], c2 = c + dc[i];
        if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m &&
            dist[r][c] + g[r2][c2] < dist[r2][c2]) {
          dist[r2][c2] = dist[r][c] + g[r2][c2];
          pq.push({dist[r2][c2], r2, c2});
        }
      }
    }

    printf("%d\n", dist[n - 1][m - 1]);
  }
  return 0;
}
