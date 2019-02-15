// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) permutationdescent
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

#define MOD 1001113

int dp[110][110];

int main() {
  int p;
  GET(p);
  while (p--) {
    int k, N, v;
    GET(k);
    GET(N);
    GET(v);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < 110; ++i) {
      dp[i][0] = 1;
    }

    for (int n = 1; n < N; ++n) {
      for (int d = 0; d < v; ++d) {
        dp[n + 1][d + 1] =
            (((n - d) * dp[n][d]) % MOD + ((d + 2) * dp[n][d + 1]) % MOD) % MOD;
      }
    }

    printf("%d %d\n", k, dp[N][v]);
  }
  return 0;
}
