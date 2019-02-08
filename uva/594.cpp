// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 594
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  while (GET(n) > 0) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
      int byte = (n >> (i * 8)) & (0xFF);
      res |= byte << ((4 - i - 1) * 8);
    }
    printf("%d converts to %d\n", n, res);
  }
  return 0;
}
