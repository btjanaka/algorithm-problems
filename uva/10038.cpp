// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10038
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

bool diffs[3030];

int main() {
  int n;
  while (GET(n) > 0) {
    memset(diffs, false, sizeof(diffs));
    int prev, cur;
    for (int i = 0; i < n; ++i) {
      GET(cur);
      if (i != 0) {
        int diff = abs(cur - prev);
        diffs[diff] = true;
      }
      prev = cur;
    }

    bool ok = true;
    for (int i = 1; i <= n - 1; ++i) {
      ok &= diffs[i];
    }
    if (ok)
      printf("Jolly\n");
    else
      printf("Not jolly\n");
  }
  return 0;
}
