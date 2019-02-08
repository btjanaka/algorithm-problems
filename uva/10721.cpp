// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10721
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

ll dp[55][55][55];
ll f(int n, int k, int m) {
  if (n <= 0) return 0;
  if (dp[n][k][m] != -1) return dp[n][k][m];
  if (m * k < n) return 0;
  if (k == 1) return dp[n][k][m] = 1;
  if (k == n) return dp[n][k][m] = 1;
  if (k > n) return dp[n][k][m] = 0;

  dp[n][k][m] = 0;
  for (int i = 1; i <= m; ++i) {
    dp[n][k][m] += f(n - i, k - 1, m);
  }

  return dp[n][k][m];
}

int main() {
  int n, k, m;
  memset(dp, -1, sizeof(dp));
  while (scanf("%d %d %d", &n, &k, &m) > 0) {
    printf("%lld\n", f(n, k, m));
  }
  return 0;
}
