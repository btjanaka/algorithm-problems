// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 497
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  getchar();
  getchar();
  char buf[30];
  while (ca--) {
    // input
    vector<int> a;
    int x;
    while (fgets(buf, 30, stdin) && buf[0] != '\n') {
      sscanf(buf, "%d", &x);
      a.push_back(x);
    }

    // LIS
    vector<ii> dp(a.size(), {-1, -1});
    for (int i = 0; i < a.size(); ++i) {
      ii mx = {1, -1};
      for (int j = 0; j < i; ++j) {
        if (a[j] < a[i]) {
          mx = max(mx, {dp[j].first + 1, j});
        }
      }
      dp[i] = mx;
    }

    // output
    auto resi = max_element(dp.begin(), dp.end());
    ii res = *resi;
    int cur = resi - dp.begin();
    printf("Max hits: %d\n", res.first);
    stack<int> to_print;
    while (res.second != -1) {
      to_print.push(a[cur]);
      cur = res.second;
      res = dp[res.second];
    }
    to_print.push(a[cur]);
    while (!to_print.empty()) {
      printf("%d\n", to_print.top());
      to_print.pop();
    }
    if (ca) printf("\n");
  }
  return 0;
}
