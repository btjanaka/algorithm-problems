// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeForces) 727c
// Title: Guess the Array
// Link: http://codeforces.com/contest/727/problem/C
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int response(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  int x;
  GET(x);
  return x;
}

int main() {
  int n;
  cin >> n;
  vector<int> res(n + 1);

  // Group the first 3 together; if you have the equations:
  //   a + b = s1
  //   b + c = s2
  //   a + c = s3
  // You can solve for a, b, and c in terms of s (this derivation is trivial and
  // is left as an exercise to the reader ;D)
  int s[4];
  s[1] = response(1, 2);
  s[2] = response(2, 3);
  s[3] = response(1, 3);
  res[1] = (s[1] - s[2] + s[3]) / 2;
  res[2] = (s[1] + s[2] - s[3]) / 2;
  res[3] = (-s[1] + s[2] + s[3]) / 2;

  // with some elements determined, the rest are trivial
  for (int i = 4; i <= n; ++i) {
    res[i] = response(1, i) - res[1];
  }

  // final output
  printf("!");
  for (int i = 1; i <= n; ++i) printf(" %d", res[i]);
  printf("\n");
  fflush(stdout);

  return 0;
}
