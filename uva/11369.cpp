// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11369
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int price[20020];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n;
    GET(n);
    for (int i = 0; i < n; ++i) GET(price[i]);
    sort(price, price + n);

    int res = 0;
    for (int i = n - 3; i >= 0; i -= 3) {
      res += price[i];
    }
    printf("%d\n", res);
  }
  return 0;
}
