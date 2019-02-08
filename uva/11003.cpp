// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11003
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// note: boxes already "sorted" by serial number - just use input order
int n;
int w[1010];
int m[1010];

int dp[1010][3030];
int f(int id, int rem) {
  if (dp[id][rem] >= 0) return dp[id][rem];

  if (id == n) {
    dp[id][rem] = 0;
  } else if (rem == 0) {
    dp[id][rem] = 0;
  } else {
    dp[id][rem] = f(id + 1, rem);
    if (rem >= w[id]) {
      // will not care about weight if this is first box
      if (rem == 3029) {
        dp[id][rem] = max(dp[id][rem], 1 + f(id + 1, m[id]));
      } else {
        dp[id][rem] = max(dp[id][rem], 1 + f(id + 1, min(rem - w[id], m[id])));
      }
    }
  }

  return dp[id][rem];
}

int main() {
  while (GET(n) && n) {
    // input
    for (int i = 0; i < n; ++i) {
      GET(w[i]);
      GET(m[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 3029));
  }
  return 0;
}
