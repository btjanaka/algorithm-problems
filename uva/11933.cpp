// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11933
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  while (GET(n) && n) {
    int a = 0, b = 0;
    int odd_i = 1;
    for (int i = 0; i < 32; ++i) {
      if (n & (1 << i)) {
        if (odd_i & 1) {
          a |= 1 << i;
        } else {
          b |= 1 << i;
        }
        odd_i++;
      }
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
