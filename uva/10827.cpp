#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// 4 copies of the torus
int torus[160][160];
int sums[160][160];
int n;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    GET(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        GET(torus[i][j]);
        torus[i + n][j] = torus[i][j + n] = torus[i + n][j + n] = torus[i][j];
      }
    }

    // Make sums
    int nd = 2 * n;
    for (int i = 0; i < nd; ++i) {
      for (int j = 0; j < nd; ++j) {
        sums[i][j] = torus[i][j];
        if (i > 0) sums[i][j] += sums[i - 1][j];
        if (j > 0) sums[i][j] += sums[i][j - 1];
        if (i > 0 && j > 0) sums[i][j] -= sums[i - 1][j - 1];
      }
    }

    // Find max
    int mx = INT_MIN;
    for (int r0 = 0; r0 < nd; ++r0) {
      for (int c0 = 0; c0 < nd; ++c0) {
        for (int r = r0; r < min(r0 + n, nd); ++r) {
          for (int c = c0; c < min(c0 + n, nd); ++c) {
            int cur_sum = sums[r][c];
            if (r0 > 0) cur_sum -= sums[r0 - 1][c];
            if (c0 > 0) cur_sum -= sums[r][c0 - 1];
            if (r0 > 0 && c0 > 0) cur_sum += sums[r0 - 1][c0 - 1];
            mx = cur_sum > mx ? cur_sum : mx;
          }
        }
      }
    }

    cout << mx << endl;
  }
  return 0;
}
