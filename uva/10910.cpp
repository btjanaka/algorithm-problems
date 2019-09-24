// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10910
// Title: Marks Distribution
// Link:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1851
// Idea: Keep a lookup table storing T and N. See main.
// Difficulty: medium
// Tags: dp, dynamic-programming
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  // F(n,t) = 1 if n = 1
  //          0 if n * P > t
  //          1 if n * P = t
  //          sum(F(n-1, t-i) for i in {P,..,t-(n-1)*P})  otherwise

  int ca;
  GET(ca);
  while (ca--) {
    int N, T, P;
    GET(N);
    GET(T);
    GET(P);
    vector<vi> dp(N + 1, vi(T + 1));
    for (int n = 1; n <= N; ++n) {
      for (int t = 0; t <= T; ++t) {
        if (n == 1) {
          dp[n][t] = 1;
        } else if (n * P > t) {
          dp[n][t] = 0;
        } else if (n * P == t) {
          dp[n][t] = 1;
        } else {
          dp[n][t] = 0;
          for (int i = t - (n - 1) * P; i >= P; --i) {
            dp[n][t] += dp[n - 1][t - i];
          }
        }
      }
    }
    printf("%d\n", dp[N][T]);
  }

  return 0;
}
