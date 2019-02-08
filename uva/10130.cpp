// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10130
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int n, g;
int p[1010];
int w[1010];
int mw;

int dp[1010][40];
int f(int id, int cur) {
  if (id == n) return 0;
  if (cur == mw) return 0;

  if (dp[id][cur] >= 0) return dp[id][cur];

  dp[id][cur] = f(id + 1, cur);
  if (cur + w[id] <= mw)
    dp[id][cur] = max(dp[id][cur], p[id] + f(id + 1, cur + w[id]));

  return dp[id][cur];
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    GET(n);
    for (int i = 0; i < n; ++i) {
      GET(p[i]);
      GET(w[i]);
    }

    int tot = 0;
    GET(g);
    for (int i = 0; i < g; ++i) {
      GET(mw);
      memset(dp, -1, sizeof(dp));
      tot += f(0, 0);
    }

    printf("%d\n", tot);
  }
  return 0;
}
