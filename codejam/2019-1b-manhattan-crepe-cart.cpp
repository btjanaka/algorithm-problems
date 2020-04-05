// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeJam) 2019-1b-manhattan-crepe-cart
// Title: Manhattan Crepe Cart
// Link:
// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/000000000012295c
// Idea:
// Difficulty: medium
// Tags: arrays
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    int p, q;
    GET(p);
    GET(q);
    vector<tuple<int, int, char>> horiz, vert;
    for (int i = 0; i < p; ++i) {
      int xi, yi;
      char di;
      scanf("%d %d %c", &xi, &yi, &di);
      if (di == 'N' | di == 'S') {
        vert.push_back({xi, yi, di});
      } else {
        horiz.push_back({xi, yi, di});
      }
    }

    // Determine for each axis
    int mxh = -1;
    int xf = -1;
    for (int i = 0; i <= q; ++i) {
      int count = 0;
      for (int j = 0; j < horiz.size(); ++j) {
        int x, y;
        char d;
        tie(x, y, d) = horiz[j];
        if ((d == 'E' && i > x) || (d == 'W' && i < x)) ++count;
      }
      if (count > mxh) {
        mxh = count;
        xf = i;
      }
    }

    int mxy = -1;
    int yf = -1;
    for (int i = 0; i <= q; ++i) {
      int count = 0;
      for (int j = 0; j < vert.size(); ++j) {
        int x, y;
        char d;
        tie(x, y, d) = vert[j];
        if ((d == 'N' && i > y) || (d == 'S' && i < y)) ++count;
      }
      if (count > mxy) {
        mxy = count;
        yf = i;
      }
    }

    printf("Case #%d: %d %d\n", caa, xf, yf);
  }
  return 0;
}
