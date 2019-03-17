// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 352
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n;
char img[30][30];
bool visited[30][30];
int dr[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int dc[8] = {1, 1, 1, 0, 0, -1, -1, -1};

void bfs(int sr, int sc) {
  queue<ii> q;
  q.push({sr, sc});
  visited[sr][sc] = true;
  while (!q.empty()) {
    int r, c;
    tie(r, c) = q.front();
    q.pop();
    for (int i = 0; i < 8; ++i) {
      int r2 = r + dr[i], c2 = c + dc[i];
      if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < n && img[r2][c2] == '1' &&
          !visited[r2][c2]) {
        q.push({r2, c2});
        visited[r2][c2] = true;
      }
    }
  }
}

int main() {
  for (int ca = 1; GET(n) > 0; ++ca) {
    getchar();
    for (int i = 0; i < n; ++i) fgets(img[i], n + 2, stdin);

    int comps = 0;
    memset(visited, false, sizeof(visited));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (img[r][c] == '1' && !visited[r][c]) {
          bfs(r, c);
          ++comps;
        }
      }
    }

    printf("Image number %d contains %d war eagles.\n", ca, comps);
  }
  return 0;
}
