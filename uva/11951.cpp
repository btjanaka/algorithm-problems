// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11951
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  ll a[110][110];
  for (int caa = 1; caa <= ca; ++caa) {
    int n, m, k;
    GET(n);
    GET(m);
    GET(k);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%lld", &a[i][j]);
        if (i > 0) a[i][j] += a[i - 1][j];
        if (j > 0) a[i][j] += a[i][j - 1];
        if (i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
      }
    }

    ll mxa = 0, mnv = 0;
    for (int r0 = 0; r0 < n; ++r0) {
      for (int c0 = 0; c0 < m; ++c0) {
        for (int r = r0; r < n; ++r) {
          for (int c = c0; c < m; ++c) {
            ll cost = a[r][c];
            if (r0 > 0) cost -= a[r0 - 1][c];
            if (c0 > 0) cost -= a[r][c0 - 1];
            if (r0 > 0 && c0 > 0) cost += a[r0 - 1][c0 - 1];
            int area = (r - r0 + 1) * (c - c0 + 1);
            if (area > mxa && cost <= k || area == mxa && cost < mnv) {
              mxa = area;
              mnv = cost;
            }
          }
        }
      }
    }

    printf("Case #%d: %lld %lld\n", caa, mxa, mnv);
  }
  return 0;
}
