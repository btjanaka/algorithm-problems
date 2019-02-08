// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10370
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
    int n;
    GET(n);
    double s[1010];
    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
      GED(s[i]);
      avg += s[i];
    }
    avg /= double(n);
    int above = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] > avg) ++above;
    }
    printf("%.3lf%%\n", 100.0 * double(above) / double(n));
  }
  return 0;
}
