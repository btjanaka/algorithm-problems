// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10616
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int nums[250];
ll dp[250][25][15];  // current sum, current value mod d, numbers picked

// count number of ways to get m numbers that are divisible by d
int count(int d, int m, int cur, int tot, int i, int n) {
  if (cur == m) {
    if (tot == 0)
      return 1;
    else
      return 0;
  }
  if (i == n) return 0;

  if (dp[i + 1][tot][cur] < 0)
    dp[i + 1][tot][cur] = count(d, m, cur, tot, i + 1, n);
  int new_tot = (tot + nums[i] % d) % d;
  if (new_tot < 0) new_tot += d;
  if (dp[i + 1][new_tot][cur + 1] < 0)
    dp[i + 1][new_tot][cur + 1] = count(d, m, cur + 1, new_tot, i + 1, n);

  return dp[i + 1][tot][cur] + dp[i + 1][new_tot][cur + 1];
}

int main() {
  int n, q;
  for (int ca = 1; GET(n) && GET(q) && !(!n && !q); ++ca) {
    printf("SET %d:\n", ca);
    for (int i = 0; i < n; ++i) GET(nums[i]);
    int d, m;
    for (int i = 1; i <= q; ++i) {
      memset(dp, -1, sizeof(dp));
      GET(d);
      GET(m);
      ll res = count(d, m, 0, 0, 0, n);

      printf("QUERY %d: %lld\n", i, res);
    }
  }
  return 0;
}
