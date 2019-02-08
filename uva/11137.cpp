// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11137
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int c[21];
  for (int i = 0; i < 21; ++i) c[i] = (i + 1) * (i + 1) * (i + 1);

  int n;
  while (GET(n) > 0) {
    ll dp[10000];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 21; ++i) {
      for (int j = c[i]; j <= n; ++j) {
        dp[j] += dp[j - c[i]];
      }
    }

    printf("%lld\n", dp[n]);
  }
  return 0;
}
