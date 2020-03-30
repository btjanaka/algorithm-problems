// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) purplerain
// Title: Purple Rain
// Link: https://open.kattis.com/problems/purplerain
// Idea: Kadane's algorithm.
// Difficulty: medium
// Tags: dynamic-programming, kadane
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int r[100100];
int n;

pair<int, ii> kadane() {
  int mx = r[0];
  int lpos = 0;
  int rpos = 0;

  int cur = r[0];
  int lcur = 0;
  int rcur = 0;
  for (int i = 1; i < n; ++i) {
    if (cur < 0) {
      lcur = i;
      cur = 0;
    }
    cur += r[i];
    if (cur > mx) {
      mx = cur;
      lpos = lcur;
      rpos = i;
    }
  }

  return {mx, {lpos, rpos}};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (getline(cin, s)) {
    n = s.size();

    // try two ways - one with looking for red and one with looking for blue
    // in each case consider the target as 1 or -1
    for (int i = 0; i < n; ++i) {
      r[i] = s[i] == 'R' ? 1 : -1;
    }
    pair<int, ii> rmx = kadane();
    for (int i = 0; i < n; ++i) {
      r[i] = s[i] == 'B' ? 1 : -1;
    }
    pair<int, ii> bmx = kadane();

    // output
    ii res;
    if (rmx.first > bmx.first) {
      res = rmx.second;
    } else if (rmx.first == bmx.first) {
      res = min(rmx.second, bmx.second);
    } else {
      res = bmx.second;
    }
    printf("%d %d\n", res.first + 1, res.second + 1);
  }

  return 0;
}
