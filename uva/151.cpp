// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 151
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int calc(int n) {
  for (int m = 1; m <= n; ++m) {
    vector<bool> cities(n, false);
    int cur = 0;
    int seen = 0;
    while (seen != n) {
      cities[cur] = true;
      ++seen;
      // advance to next city
      if (seen != n) {
        for (int i = 0; i < m; ++i) {
          if (!cities[cur]) {
            cur = (cur + 1) % n;
          }
          while (cities[cur]) {
            cur = (cur + 1) % n;
          }
        }
      }
    }
    if (cur == 12) return m;
  }
  return -1;
}

int res[101];
void precalculate() {
  for (int i = 1; i < 101; ++i) {
    res[i] = calc(i);
  }
}

int main() {
  int n;
  precalculate();
  while (GET(n) && n) {
    printf("%d\n", res[n]);
  }
  return 0;
}
