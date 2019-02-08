// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10812
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int s, d, x, y;
    GET(s);
    GET(d);
    x = (s + d) / 2;
    y = s - x;
    if (x + y == s && abs(x - y) == d && x >= 0 && y >= 0) {
      printf("%d %d\n", max(x, y), min(x, y));
    } else {
      x = (s - d) / 2;
      y = s - x;
      if (x + y == s && abs(x - y) == d && x >= 0 && y >= 0) {
        printf("%d %d\n", max(x, y), min(x, y));
      } else {
        printf("impossible\n");
      }
    }
  }
  return 0;
}
