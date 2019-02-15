// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) divisible
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

ll a[50050];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int d, n;
    GET(d);
    GET(n);
    int x;

    // store cumulative sums instead of numbers
    for (int i = 0; i < n; ++i) {
      GET(x);
      if (i == 0) {
        a[i] = x;
      } else {
        a[i] = a[i - 1] + x;
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = -1; j < i; ++j) {
        if ((a[j] - (i < 0 ? 0 : a[i])) % d == 0) {
          ++res;
        }
      }
    }

    printf("%d\n", res);
  }
  return 0;
}
