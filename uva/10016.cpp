// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10016
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int sq[110][110];

int main() {
  int ca;
  GET(ca);
  int n, ring, t;
  while (ca--) {
    GET(n);
    ring = (n + 1) / 2;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        GET(sq[i][j]);
      }
    }

    int cc, lim;
    for (int i = 0; i < ring; ++i) {
      lim = n - i;
      GET(t);
      for (int j = 0; j < t; ++j) {
        GET(cc);
        switch (cc) {
          case 1:
            for (int r = i; r < n / 2; ++r) {
              for (int c = i; c < lim; ++c) {
                if (c == i || c == lim - 1 || r == i) {
                  swap(sq[r][c], sq[n - r - 1][c]);
                }
              }
            }
            break;
          case 2:
            for (int r = i; r < lim; ++r) {
              for (int c = i; c < n / 2; ++c) {
                if (r == i || r == lim - 1 || c == i) {
                  swap(sq[r][c], sq[r][n - c - 1]);
                }
              }
            }
            break;
          case 3:
            for (int r = i; r < lim; ++r) {
              for (int c = i; c < lim; ++c) {
                if (r == i || c == lim - 1) {
                  swap(sq[r][c], sq[c][r]);
                }
              }
            }
            break;
          case 4:
            for (int r = i; r < lim; ++r) {
              for (int c = i; c < lim; ++c) {
                if (r == i || c == i) {
                  swap(sq[r][c], sq[n - c - 1][n - r - 1]);
                }
              }
            }
            break;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        printf("%d%c", sq[i][j], j == n - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
