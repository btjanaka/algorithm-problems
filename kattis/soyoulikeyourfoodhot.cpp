// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) soyoulikeyourfoodhot
// Title: So You Like Your Food Hot?
// Link: https://open.kattis.com/problems/soyoulikeyourfoodhot
// Idea: This problem can be brute forced, but make sure to use integers with
// cent amounts to avoid precision errors.
// Difficulty: easy
// Tags: math, brute-force
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int pt, p1, p2;
  for (int i = 0; i < 3; ++i) {
    int a, b;
    scanf("%d.%d", &a, &b);
    int x = a * 100 + b;
    if (i == 0)
      pt = x;
    else if (i == 1)
      p1 = x;
    else
      p2 = x;
  }

  bool ok = false;
  for (int n1 = 0; n1 * p1 <= pt; ++n1) {
    if ((pt - (n1 * p1)) % p2 == 0) {
      ok = true;
      printf("%d %d\n", n1, (pt - (n1 * p1)) / p2);
    }
  }

  if (!ok) printf("none\n");

  return 0;
}
