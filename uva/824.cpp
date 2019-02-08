// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 824
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int g[3][3];

int main() {
  int x, y, d;
  int xi, yi, si;
  g[1][1] = 1;
  while (GET(x) && x != -1) {
    GET(y);
    GET(d);
    int xc = x - 1, yc = y - 1;
    for (int i = 0; i < 8; ++i) {
      GET(xi);
      GET(yi);
      GET(si);
      g[2 - (yi - yc)][xi - xc] = si;
    }

    // for (int i = 0; i < 3; ++i) {
    //   for (int j = 0; j < 3; ++j) {
    //     printf("%d", g[i][j]);
    //   }
    //   printf("\n");
    // }

    // generate surface in different dirs
    int dirs[8] = {g[0][1], g[0][0], g[1][0], g[2][0],
                   g[2][1], g[2][2], g[1][2], g[0][2]};

    // decide - realize that you can never come from the direction to your back
    // right (d + 5) % 8, and that you will always prioritize (d - 2)% 8 up to
    // (d + 4) % 8
    int d0 = d - 2;
    if (d0 < 0) d0 += 8;
    int df = (d + 5) % 8;
    int res = -1;
    for (int i = d0; i != df; i = (i + 1) % 8) {
      if (dirs[i]) {
        res = i;
        break;
      }
    }

    printf("%d\n", res);
  }
  return 0;
}
