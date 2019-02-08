// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11450
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// bottom up

int k[25];
int cl[25][25];
bool dp[2][210];
int m, c;

int main() {
  int n;
  GET(n);
  while (n--) {
    GET(m);
    GET(c);

    FOR(i, 0, c) {
      GET(k[i]);
      FOR(j, 0, k[i]) { GET(cl[i][j]); }
    }

    memset(dp, false, sizeof(dp));

    // bottom up dp with space saving trick

    // init
    for (int i = 0; i < k[0]; ++i) {
      int sub = m - cl[0][i];
      if (sub >= 0) dp[0][sub] = true;
    }

    int cur = 1, prev = 0;
    for (int row = 1; row < c; ++row) {
      memset(dp[cur], false, sizeof(dp[cur]));
      for (int i = 0; i <= m; ++i) {
        if (dp[prev][i]) {
          for (int j = 0; j < k[row]; ++j) {
            int sub = i - cl[row][j];
            if (sub >= 0) {
              dp[cur][sub] = true;
            }
          }
        }
      }
      int tmp = cur;
      cur = prev;
      prev = tmp;
    }

    int res = -1;
    for (int i = 0; i <= m; ++i) {
      if (dp[prev][i]) {
        res = m - i;
        break;
      }
    }

    if (res < 0)
      printf("no solution\n");
    else
      printf("%d\n", res);
  }
  return 0;
}

// top down

// int k[25];
// int cl[25][25];
// int dp[210][25];
// int m, c;

// int shop(int money, int g) {
//   if (money < 0) return INT_MIN;
//   if (g == c) return m - money;

//   if (dp[money][g] > -1) return dp[money][g];

//   for (int i = 0; i < k[g]; ++i) {
//     dp[money][g] = max(dp[money][g], shop(money - cl[g][i], g + 1));
//   }
//   return dp[money][g];
// }

// int main() {
//   int n;
//   GET(n);
//   while (n--) {
//     GET(m);
//     GET(c);

//     FOR(i, 0, c) {
//       GET(k[i]);
//       FOR(j, 0, k[i]) { GET(cl[i][j]); }
//     }

//     memset(dp, -1, sizeof(dp));

//     int res = shop(m, 0);
//     if (res < 0)
//       printf("no solution\n");
//     else
//       printf("%d\n", res);
//   }
//   return 0;
// }
