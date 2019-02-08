// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1196
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

pair<int, int> b[10010];
int dp[10010];

int main() {
  int n;
  while (GET(n) && n) {
    for (int i = 0; i < n; ++i) {
      GET(b[i].first);
      GET(b[i].second);
    }
    sort(b, b + n);

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      int mx = 0;
      for (int j = 0; j < i; ++j) {
        if (b[i].second >= b[j].second) {
          mx = max(mx, dp[j]);
        }
      }
      dp[i] = mx + 1;
    }

    printf("%d\n", *max_element(dp, dp + n));
  }
  printf("*\n");
  return 0;
}
