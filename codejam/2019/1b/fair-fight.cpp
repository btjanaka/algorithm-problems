// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) Fair Fight
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
    int n, k;
    GET(n);
    GET(k);
    vector<int> c, d;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      c.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      d.push_back(x);
    }

    int res = 0;

    for (int l = 0; l < n; ++l) {
      for (int r = l; r < n; ++r) {
        int cmax = *max_element(c.begin() + l, c.begin() + r + 1);
        int dmax = *max_element(d.begin() + l, d.begin() + r + 1);
        if (abs(dmax - cmax) <= k) ++res;
      }
    }

    printf("Case #%d: %d\n", caa, res);
  }
  return 0;
}
