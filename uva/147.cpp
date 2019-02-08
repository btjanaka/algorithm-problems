// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 147
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int coins[] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
int c = 11;
ll dp[12][6001];

ll f(int id, int val) {
  if (id < c && val >= 0 && dp[id][val] != -1) return dp[id][val];

  if (id == c) {
    return 0;
  } else if (val < 0) {
    return 0;
  } else if (val == 0) {
    dp[id][val] = 1;
  } else {
    dp[id][val] = f(id + 1, val) + f(id, val - coins[id]);
  }

  return dp[id][val];
}

int main() {
  memset(dp, -1, sizeof(dp));
  while (true) {
    // input
    int base, dec;
    scanf("%d.%d", &base, &dec);
    int n = (base * 100 + dec) / 5;
    if (n == 0) break;

    // output
    printf("%3d.%02d%17lld\n", base, dec, f(0, n));
  }

  // for (int i = 0; i < 11; ++i) {
  //   for (int j = 0; j < 40; ++j) {
  //     printf("%2lld%c", dp[i][j], j == 39 ? '\n' : ' ');
  //   }
  // }

  return 0;
}
