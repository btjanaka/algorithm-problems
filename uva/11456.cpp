// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11456
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// calculate max(LIS(i) + LDS(i) - 1)

int cars[2020];
int lis[2020];
int lds[2020];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n;
    GET(n);
    for (int i = 0; i < n; ++i) GET(cars[i]);

    // have to reverse because lis and lds will give the length up to that point
    // from left to right, but you want the other way
    for (int i = 0; i < n / 2; ++i) swap(cars[i], cars[n - i - 1]);

    // find lis's
    vector<int> dp(1, cars[0]);
    lis[0] = 1;
    for (int i = 1; i < n; ++i) {
      int c = cars[i];
      auto pos = lower_bound(dp.begin(), dp.end(), c,
                             [](int a, int b) { return a < b; });
      if (pos == dp.end()) {
        dp.push_back(c);
        lis[i] = dp.size();
      } else {
        *pos = c;
        lis[i] = pos - dp.begin() + 1;
      }
    }

    // find lds's
    dp.clear();
    dp.push_back(cars[0]);
    lds[0] = 1;
    for (int i = 1; i < n; ++i) {
      int c = cars[i];
      auto pos = lower_bound(dp.begin(), dp.end(), c,
                             [](int a, int b) { return a > b; });
      if (pos == dp.end()) {
        dp.push_back(c);
        lds[i] = dp.size();
      } else {
        *pos = c;
        lds[i] = pos - dp.begin() + 1;
      }
    }

    // find max and print
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, lis[i] + lds[i] - 1);
    }
    printf("%d\n", mx);
  }
  return 0;
}
