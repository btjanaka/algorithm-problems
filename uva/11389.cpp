// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11389
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, r;
  scanf("%d %d %d\n", &n, &d, &r);
  while (n > 0 && d > 0 && r > 0) {
    vector<int> morning;
    vector<int> afternoon;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      morning.push_back(x);
    }
    sort(morning.begin(), morning.end());
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      afternoon.push_back(x);
    }
    sort(afternoon.begin(), afternoon.end());

    int tot = 0;
    for (int i = 0; i < n; ++i) {
      tot += max(0, morning[i] + afternoon[n - i - 1] - d);
    }
    printf("%d\n", tot * r);
    scanf("%d %d %d\n", &n, &d, &r);
  }
  return 0;
}
