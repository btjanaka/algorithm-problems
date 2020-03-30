// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) sock-merchant
// Title: Sock Merchant
// Link: https://www.hackerrank.com/challenges/sock-merchant/problem
// Idea: Count up how many of each sock there are, then count up pairs.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n;
  GET(n);
  unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int x;
    GET(x);
    if (m.find(x) == m.end()) {
      m[x] = 0;
    }
    ++m[x];
  }
  int tot = 0;
  for (auto& x : m) {
    tot += x.second / 2;
  }
  printf("%d\n", tot);
  return 0;
}
