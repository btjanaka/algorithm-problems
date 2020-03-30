// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) speed
// Title: Need for Speed
// Link: https://open.kattis.com/problems/speed
// Idea:
// Difficulty: medium
// Tags: binary-search
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

double seg[1010][2];
int n;
double t;

bool works(double c) {
  double tot = 0.0;
  for (int i = 0; i < n; ++i) {
    if (seg[i][1] + c <= 0.0) return false;
    double t = seg[i][0] / (seg[i][1] + c);
    tot += t;
  }
  return (tot - t) < 1e-9;
}

int main() {
  GET(n);
  GED(t);
  for (int i = 0; i < n; ++i) {
    scanf("%lf %lf", &seg[i][0], &seg[i][1]);
  }

  double lo = -1e9, hi = 1e9, ans = 0.0;
  while (abs(hi - lo) > 1e-9) {
    double mid = lo + (hi - lo) / 2.0;
    if (works(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
    ans = mid;
  }

  printf("%.9lf\n", ans);

  return 0;
}
