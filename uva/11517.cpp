// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11517
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  int dp[20001];
  int c[110];
  while (ca--) {
    // input
    int p;
    GET(p);
    int n;
    GET(n);
    for (int i = 0; i < n; ++i) GET(c[i]);

    // generate dp table - go backwards through the values to avoid repeating
    // coins - i.e. we can only use each coin once
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int j = 0; j < n; ++j) {
      for (int i = 20000; i >= 0; --i) {
        if (dp[i] == -1) continue;
        int next = i + c[j];
        if (next > 20000) continue;
        if (dp[next] == -1)
          dp[next] = dp[i] + 1;
        else
          dp[next] = min(dp[next], dp[i] + 1);
      }
    }

    // find nearest price and output
    int res;
    for (res = p; dp[res] == -1; ++res)
      ;
    printf("%d %d\n", res, dp[res]);
  }
  return 0;
}
