// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10337
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int w[10][1010];
int x;
int dp[10][1010];  // min cost to get from that altitude and position to n - 1,0
int f(int alt, int pos) {
  if (dp[alt][pos] != -1) return dp[alt][pos];
  if (pos == x - 1 && alt > 1) return dp[alt][pos] = INT_MAX / 2;
  if (pos == x - 1 && alt == 0) return dp[alt][pos] = 30 - w[alt][pos];
  if (pos == x - 1 && alt == 1) return dp[alt][pos] = 20 - w[alt][pos];

  dp[alt][pos] = 30 + f(alt, pos + 1);
  if (alt < 9) dp[alt][pos] = min(dp[alt][pos], 60 + f(alt + 1, pos + 1));
  if (alt > 0) dp[alt][pos] = min(dp[alt][pos], 20 + f(alt - 1, pos + 1));
  dp[alt][pos] -= w[alt][pos];

  return dp[alt][pos];
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    GET(x);
    x /= 100;
    for (int i = 9; i >= 0; --i) {
      for (int j = 0; j < x; ++j) {
        GET(w[i][j]);
      }
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n\n", f(0, 0));
  }
  return 0;
}
