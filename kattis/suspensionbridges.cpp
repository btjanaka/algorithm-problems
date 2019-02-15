// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) suspensionbridges
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

double d, s;

int main() {
  GED(d);
  GED(s);

  double lo = -1e9, hi = 1e9, a = 0.0;
  while (true) {
    double mid = lo + (hi - lo) / 2.0;
    double lhs = mid + s;
    double rhs = mid * cosh(d / (2.0 * mid));
    if (abs(lhs - rhs) < 1e-9) {
      a = mid;
      break;
    }
    if (lhs > rhs) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%.6lf\n", 2.0 * a * sinh(d / (2.0 * a)));
  return 0;
}
