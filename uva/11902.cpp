// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11902
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int n;
int g[110][110];
bool dom[110][110];
bool reachi[110];
bool reach[110];
bool visited[110];

void dfs_reach(int cur, int avoid) {
  visited[cur] = true;
  if (cur == avoid) return;
  reach[cur] = true;
  for (int i = 0; i < n; ++i) {
    if (!visited[i] && g[cur][i]) {
      dfs_reach(i, avoid);
    }
  }
}

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    GET(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        GET(g[i][j]);
      }
    }

    // find originally reachable vertices
    memset(reach, false, sizeof(reach));
    memset(visited, false, sizeof(reach));
    dfs_reach(0, -1);
    memcpy(reachi, reach, sizeof(reach));

    // try removing each vertex and see which ones are still reachable - if any
    // are not reachable then they are dominated
    memset(dom, false, sizeof(dom));
    for (int i = 0; i < n; ++i) {
      if (!reachi[i]) continue;
      memset(reach, false, sizeof(reach));
      memset(visited, false, sizeof(reach));
      dfs_reach(0, i);
      for (int j = 0; j < n; ++j) {
        if (reachi[j] && !reach[j]) {
          dom[i][j] = true;
        }
      }
    }

    // output
    printf("Case %d:\n", caa);
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        putchar('+');
        for (int j = 0; j < 2 * n - 1; ++j) putchar('-');
        putchar('+');
        putchar('\n');
      }
      putchar('|');
      for (int j = 0; j < n; ++j) printf("%c|", dom[i][j] ? 'Y' : 'N');
      putchar('\n');

      putchar('+');
      for (int j = 0; j < 2 * n - 1; ++j) putchar('-');
      putchar('+');
      putchar('\n');
    }
  }
  return 0;
}
