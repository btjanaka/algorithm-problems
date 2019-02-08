// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 357
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

ll dp[30030];

int main() {
  int c[5] = {1, 5, 10, 25, 50};
  dp[0] = 1;
  for (int i = 0; i < 5; ++i) {
    for (int j = c[i]; j <= 30000; ++j) {
      dp[j] += dp[j - c[i]];
    }
  }
  int n;
  while (GET(n) > 0) {
    if (dp[n] == 1) {
      printf("There is only 1 way to produce %d cents change.\n", n);
    } else {
      printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
    }
  }
  return 0;
}
