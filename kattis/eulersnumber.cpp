// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) eulersnumber
// Title: Euler's Number
// Link: https://open.kattis.com/problems/eulersnumber
// Idea: Implement the formula.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  GET(n);
  double res = 0.0;
  double factorial = 1.0;
  for (int i = 0; i <= n; ++i) {
    if (i != 0) factorial *= (double)i;
    res += 1.0 / factorial;
  }
  printf("%.20lf\n", res);
  return 0;
}
