// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) knapsack
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int c;
int n;
int v[2020], w[2020];
int dp[2020][2020];
bool used[2020];

int main() {
  double cd;
  while (GED(cd) > 0) {
    // input
    c = (int)cd;
    GET(n);
    for (int i = 1; i <= n; ++i) {
      GET(v[i]);
      GET(w[i]);
    }

    // iterative knapsack - too deep for recursion :(
    memset(used, false, sizeof(used));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= c; ++i) dp[0][i] = 0;  // clear beginning weights
    for (int id = 1; id <= n; ++id) {
      for (int rem = 0; rem <= c; ++rem) {
        int take = w[id] > rem ? -1 : v[id] + dp[id - 1][rem - w[id]];
        int leave = dp[id - 1][rem];
        dp[id][rem] = max(take, leave);
      }
    }

    // decide which was used
    int col = c;
    for (int id = n; id > 0; --id) {
      if (dp[id - 1][col] != dp[id][col]) {
        col -= w[id];
        used[id] = true;
      }
    }

    // print results
    printf("%d\n", accumulate(used + 1, used + n + 1, 0));
    bool first = true;
    for (int i = 0; i <= n; ++i) {
      if (used[i]) {
        if (first) {
          first = false;
        } else {
          putchar(' ');
        }
        printf("%d", i - 1);
      }
    }
    putchar('\n');
  }
  return 0;
}
