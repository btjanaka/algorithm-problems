// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10943
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int dp[110][110];
int f(int n, int k) {
  if (dp[n][k] != -1) return dp[n][k];
  if (k == 1) return dp[n][k] = 1;

  dp[n][k] = 0;
  for (int i = 0; i <= n; ++i) {
    dp[n][k] = (dp[n][k] + f(n - i, k - 1)) % 1000000;
  }

  return dp[n][k];
}

int main() {
  int n, k;
  while (GET(n) && GET(k) && (n || k)) {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(n, k));
  }
  return 0;
}
