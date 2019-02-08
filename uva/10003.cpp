// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10003
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int c[55];
int dp[55][55];
int n;
int f(int left, int right) {
  if (dp[left][right] != -1) return dp[left][right];
  if (left + 1 == right) return dp[left][right] = 0;

  dp[left][right] = INT_MAX;
  for (int i = left + 1; i < right; ++i) {
    dp[left][right] =
        min(dp[left][right], c[right] - c[left] + f(left, i) + f(i, right));
  }

  return dp[left][right];
}

int main() {
  int l;
  while (GET(l) && l) {
    GET(n);
    n += 2;
    c[0] = 0;
    for (int i = 1; i < n - 1; ++i) GET(c[i]);
    c[n - 1] = l;

    memset(dp, -1, sizeof(dp));
    printf("The minimum cutting is %d.\n", f(0, n - 1));
  }
  return 0;
}
