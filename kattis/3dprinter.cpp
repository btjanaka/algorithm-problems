// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) 3dprinter
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n;
  GET(n);
  int p = 1;
  int mx = n;
  for (int printer_d = 0; p < 10000; ++printer_d) {
    int tot = printer_d + (n / p) + (n % p > 0 ? 1 : 0);
    mx = min(tot, mx);
    p *= 2;
  }
  printf("%d\n", mx);
  return 0;
}
