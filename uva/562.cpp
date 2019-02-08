// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 562
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int m;
int c[110];
int dp[110][50001];  // only 22 mb, we are fine

int backtrack(int id, int diff) {
  int adj_diff = diff + 25000;
  if (dp[id][adj_diff] >= 0) return dp[id][adj_diff];

  if (diff < -25000 || diff > 25000) {
    return INT_MAX;  // If diff is this big we know we could have divided better
  } else if (id == m) {
    dp[id][adj_diff] = diff;
  } else {
    dp[id][adj_diff] = min(abs(backtrack(id + 1, diff + c[id])),
                           abs(backtrack(id + 1, diff - c[id])));
  }

  return dp[id][adj_diff];
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    GET(m);
    for (int i = 0; i < m; ++i) {
      GET(c[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", backtrack(0, 0));
  }
  return 0;
}
