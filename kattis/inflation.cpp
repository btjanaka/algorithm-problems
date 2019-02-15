// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) inflation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int c[200100];

int main() {
  int n;
  while (GET(n) > 0) {
    // sort canisters and iterate to find lowest fraction (or explosion)
    for (int i = 1; i <= n; ++i) GET(c[i]);

    sort(c + 1, c + n + 1);

    bool ok = true;
    double frac = 1.0;
    for (int i = 1; i <= n; ++i) {
      if (c[i] > i) {
        ok = false;
        break;
      }
      frac = min(frac, double(c[i]) / double(i));
    }

    if (ok) {
      printf("%.9lf\n", frac);
    } else {
      printf("impossible\n");
    }
  }
  return 0;
}
