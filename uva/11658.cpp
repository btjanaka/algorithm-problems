// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11658
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int n, x;
int share[110];

int dp[110][5050];
int f(int id, int amt) {
  if (dp[id][amt] >= 0) return dp[id][amt];

  if (id == n - 1) {
    if (amt > 5000) {
      return amt;
    } else {
      return INT_MAX;
    }
  } else if (amt > 5000) {
    return amt;
  } else {
    int leave = f(id + 1, amt);
    int take = f(id + 1, amt + share[id]);
    // printf("%d %d : %d %d\n", id, amt, leave, take);
    dp[id][amt] = min(leave, take);
  }

  return dp[id][amt];
}

int main() {
  while (GET(n) && GET(x) && (n || x)) {
    --x;
    int sid = 0;
    int start;
    for (int i = 0; i < n; ++i) {
      int base, dec;
      scanf("%d.%d", &base, &dec);
      if (i == x) {
        start = base * 100 + dec;
      } else {
        share[sid++] = base * 100 + dec;
      }
    }

    // for_each(share, share + n - 1, [](int i) { printf("*%d\n", i); });

    memset(dp, -1, sizeof(dp));
    int min_tot = f(0, start);

    printf("%.2lf\n", 100.0 * (double)start / min_tot);
  }
  return 0;
}
