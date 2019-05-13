// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) pizza
// Title: Pizza Delivery
// Link: https://open.kattis.com/problems/pizza
// Idea: This problem can be brute-forced, but it needs to be done in C++ and
// have shortcuts to be fast enough.
// Difficulty: easy
// Tags: brute-force
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int g[110][110];
int C, R;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    GET(C);
    GET(R);
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        GET(g[r][c]);
      }
    }

    ll mn = LLONG_MAX;
    for (int r0 = 0; r0 < R; ++r0) {
      for (int c0 = 0; c0 < C; ++c0) {
        ll cost = 0;
        bool ok = true;
        for (int r = 0; r < R; ++r) {
          for (int c = 0; c < C; ++c) {
            cost += g[r][c] * (abs(r - r0) + abs(c - c0));
            if (cost > mn) {
              ok = false;
              break;
            }
          }
          if (!ok) break;
        }
        if (ok) mn = min(cost, mn);
      }
    }

    printf("%lld blocks\n", mn);
  }
  return 0;
}
