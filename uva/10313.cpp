// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10313
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  // precalc
  ll dp[301][301];  // dp[i][k] is the number of ways to make i with k coins
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int j = 1; j <= 300; ++j) {
    for (int i = j; i <= 300; ++i) {
      for (int k = 1; k <= 300; ++k) {
        // number of ways to make i with k coins is the sum of the number of
        // ways to make i - c[x] with k - 1 coins for x in 1..300
        dp[i][k] += dp[i - j][k - 1];
      }
    }
  }

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string buf;
  while (getline(cin, buf)) {
    // input
    stringstream ss(buf);
    int x;
    vector<int> in;
    while (ss >> x) {
      in.push_back(x);
    }

    int n = in[0];
    int lo = 0, hi = n;
    switch (in.size()) {
      case 2:
        lo = 0;
        hi = in[1];
        break;
      case 3:
        lo = in[1];
        hi = in[2];
        break;
    }

    ll tot = 0;
    lo = max(0, lo);
    hi = min(300, hi);
    for (int i = lo; i <= hi; ++i) {
      tot += dp[n][i];
    }
    printf("%lld\n", tot);
  }
  return 0;
}
