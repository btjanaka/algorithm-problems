// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) coin-change
// Title: Coin Change
// Link: https://www.hackerrank.com/challenges/coin-change/problem
// Idea: Classic DP problem.
// Difficulty: medium
// Tags: dynamic-programming
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define GET(x) scanf("%d", &x)

int main() {
  int n, m;
  GET(n);
  GET(m);
  int c[60];
  ll dp[300];
  for (int i = 0; i < m; ++i) GET(c[i]);

  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = c[i]; j <= n; ++j) {
      dp[j] += dp[j - c[i]];
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}
