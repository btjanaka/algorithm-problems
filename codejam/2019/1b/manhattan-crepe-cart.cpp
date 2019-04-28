// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) Manhattan Crepe Cart
// (small input only)
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
    vector<int> x, y;
    vector<char> d;
    for (int i = 0; i < p; ++i) {
      int xi, yi;
      char di;
      scanf("%d %d %c", &xi, &yi, &di);
      x.push_back(xi);
      y.push_back(yi);
      d.push_back(di);
    }

    int mx = 0;
    int xf, yf;
    for (int xc = q; xc >= 0; --xc) {
      for (int yc = q; yc >= 0; --yc) {
        int count = 0;
        for (int i = 0; i < p; ++i) {
          if ((d[i] == 'N' && yc > y[i]) || (d[i] == 'S' && yc < y[i]) ||
              (d[i] == 'E' && xc > x[i]) || (d[i] == 'W' && xc < x[i])) {
            ++count;
          }
        }
        if (count >= mx) {
          mx = count;
          xf = xc;
          yf = yc;
        }
      }
    }

    printf("Case #%d: %d %d\n", caa, xf, yf);
  }
  return 0;
}
