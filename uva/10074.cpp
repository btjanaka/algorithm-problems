// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10074
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int a[110][110];

int main() {
  int m, n;
  while (GET(m) && GET(n) && (m || n)) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        GET(a[i][j]);
        if (i > 0) a[i][j] += a[i - 1][j];
        if (j > 0) a[i][j] += a[i][j - 1];
        if (i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
      }
    }

    int mxa = 0;
    for (int r0 = 0; r0 < m; ++r0) {
      for (int c0 = 0; c0 < n; ++c0) {
        for (int r = r0; r < m; ++r) {
          for (int c = c0; c < n; ++c) {
            int area = a[r][c];
            if (r0 > 0) area -= a[r0 - 1][c];
            if (c0 > 0) area -= a[r][c0 - 1];
            if (r0 > 0 && c0 > 0) area += a[r0 - 1][c0 - 1];
            if (area == 0) mxa = max(mxa, (r - r0 + 1) * (c - c0 + 1));
          }
        }
      }
    }

    printf("%d\n", mxa);
  }
  return 0;
}
