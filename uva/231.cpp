// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 231
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

bool get_missiles(vector<int>& ms) {
  ms.clear();
  int x;
  while (GET(x) && x != -1) {
    ms.push_back(x);
  }
  return true;
}

int main() {
  vector<int> ms;
  bool first = true;
  for (int ca = 1; get_missiles(ms) && ms.size() != 0; ++ca) {
    int n = ms.size();

    // longest non-increasing subsequence
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      int m = 0;
      for (int j = 0; j < i; ++j) {
        if (ms[j] >= ms[i]) {
          m = max(dp[j], m);
        }
      }
      dp[i] = m + 1;
    }
    int mx = *max_element(dp.begin(), dp.end());

    // output
    if (first) {
      first = false;
    } else {
      printf("\n");
    }
    printf("Test #%d:\n", ca);
    printf("  maximum possible interceptions: %d\n", mx);
  }
  return 0;
}
