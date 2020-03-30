// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) ecoins
// Title: e-Coins
// Link: https://open.kattis.com/problems/ecoins
// Idea:
// Difficulty: medium
// Tags: dynamic-programming
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int dp[330][330];
  int c[50][2];
  int ca;
  GET(ca);
  while (ca--) {
    int m, s;
    GET(m);
    GET(s);
    for (int i = 0; i < m; ++i) {
      GET(c[i][0]);
      GET(c[i][1]);
    }

    // make table
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= s; ++i) {
      for (int j = 0; j <= s; ++j) {
        if (dp[i][j] == -1) continue;
        for (int k = 0; k < m; ++k) {
          int ni = i + c[k][0];
          int nj = j + c[k][1];
          if (ni > s || nj > s) continue;
          if (dp[ni][nj] == -1) {
            dp[ni][nj] = dp[i][j] + 1;
          } else {
            dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
          }
        }
      }
    }

    // find solution
    int res = -1;
    for (int i = 0; i <= s; ++i) {
      for (int j = 0; j <= s; ++j) {
        if (i * i + j * j == s * s && dp[i][j] != -1) {
          if (res == -1)
            res = dp[i][j];
          else
            res = min(res, dp[i][j]);
        }
      }
    }

    // output
    if (res == -1) {
      printf("not possible\n");
    } else {
      printf("%d\n", res);
    }
  }
  return 0;
}
