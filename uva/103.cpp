// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 0
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// tell if a will fit in b
bool fit(const vector<int>& a, const vector<int>& b) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] >= b[i]) return false;
  }
  return true;
}

int main() {
  int k, n;
  while (scanf("%d %d", &k, &n) > 0) {
    // input
    vector<pair<int, vector<int>>> boxes;
    for (int i = 0; i < k; ++i) {
      boxes.push_back({i + 1, vector<int>()});
      for (int j = 0; j < n; ++j) {
        int x;
        GET(x);
        boxes[i].second.push_back(x);
      }
      sort(boxes[i].second.begin(), boxes[i].second.end());
    }

    sort(boxes.begin(), boxes.end(),
         [](pair<int, vector<int>>& a, pair<int, vector<int>>& b) {
           return a.second < b.second;
         });

    // for_each(boxes.begin(), boxes.end(), [](const pair<int, vector<int>>& x)
    // {
    //   printf("%d:", x.first);
    //   for_each(x.second.begin(), x.second.end(),
    //            [](int i) { printf(" %d", i); });
    //   printf("\n");
    // });

    // LIS
    vector<pair<int, int>> dp(k, {1, -1});
    for (int i = 0; i < k; ++i) {
      pair<int, int> mx = {1, -1};
      for (int j = 0; j < i; ++j) {
        if (fit(boxes[j].second, boxes[i].second)) {
          mx = max(make_pair(dp[j].first + 1, j), mx);
        }
      }
      dp[i] = mx;
    }

    // for_each(dp.begin(), dp.end(), [](const pair<int, int>& x) {
    //   printf("%d,%d ", x.first, x.second);
    // });
    // printf("\n");

    // print results
    auto itr = max_element(dp.begin(), dp.end());
    pair<int, int> cur = *itr;
    printf("%d\n", cur.first);
    int ind = itr - dp.begin();
    stack<int> to_print;
    while (cur.second != -1) {
      to_print.push(ind);
      ind = cur.second;
      cur = dp[cur.second];
    }
    to_print.push(ind);
    bool first = true;
    while (!to_print.empty()) {
      if (first)
        first = false;
      else
        putchar(' ');
      printf("%d", boxes[to_print.top()].first);
      to_print.pop();
    }
    printf("\n");
  }
  return 0;
}
