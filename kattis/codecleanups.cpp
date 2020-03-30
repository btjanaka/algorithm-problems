// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) codecleanups
// Title: Code Cleanups
// Link: https://open.kattis.com/problems/codecleanups
// Idea: Iterate through the days.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int d[370];

int main() {
  int n;
  // allow multiple inputs for debugging
  while (GET(n) > 0) {
    for (int i = 0; i < n; ++i) {
      GET(d[i]);
      --d[i];
    }
    sort(d, d + n);

    // go through days
    int di = 0;
    int cur_increase = 0;
    int cur_d = 0;
    int res = 0;
    for (int i = 0; i < 365; ++i) {
      while (i == d[di]) {
        ++cur_increase;
        ++di;
      }
      if (cur_d + cur_increase > 19) {
        ++res;
        cur_d = 0;
        cur_increase = 0;
      }
      cur_d += cur_increase;
    }
    if (cur_increase > 0) ++res;

    printf("%d\n", res);
  }
  return 0;
}
