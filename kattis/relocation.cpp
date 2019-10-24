// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) relocation
// Title: Relocation
// Link: https://open.kattis.com/problems/relocation
// Idea: Implementation.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int n, q;
  GET(n);
  GET(q);
  vector<int> loc(n + 1);
  for (int i = 1; i <= n; ++i) {
    GET(loc[i]);
  }
  for (int i = 0; i < q; ++i) {
    int cmd;
    GET(cmd);
    if (cmd == 1) {
      int c, x;
      GET(c);
      GET(x);
      loc[c] = x;
    } else {
      int a, b;
      GET(a);
      GET(b);
      printf("%d\n", abs(loc[a] - loc[b]));
    }
  }
  return 0;
}
