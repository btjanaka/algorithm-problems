// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 437
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// The Babylonians really have 6n kinds of blocks, so we just need to find LDS
// for those 3n blocks. First sort by one dimension to eliminate one. Then we
// only have to LDS using the second dimension. Third dimension is height and is
// used for the actual comparison.
int main() {
  int n;
  for (int ca = 1; GET(n) && n; ++ca) {
    // x, y, z
    vector<vector<int>> dim;

    for (int i = 0; i < n; ++i) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      dim.push_back({x, y, z});
      dim.push_back({x, z, y});
      dim.push_back({y, x, z});
      dim.push_back({y, z, x});
      dim.push_back({z, x, y});
      dim.push_back({z, y, x});
    }
    sort(
        dim.begin(), dim.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] > b[0]; });

    int sz = dim.size();
    vector<int> dp(sz);
    for (int i = 0; i < sz; ++i) {
      int mx = 0;
      for (int j = 0; j < i; ++j) {
        // Have to account for possibility that the two have equal x dims
        if (dim[j][0] > dim[i][0] && dim[j][1] > dim[i][1]) mx = max(mx, dp[j]);
      }
      dp[i] = mx + dim[i][2];
    }
    int res = *max_element(dp.begin(), dp.end());

    printf("Case %d: maximum height = %d\n", ca, res);
  }
  return 0;
}
