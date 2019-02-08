// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11479
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int caa;
  GET(caa);
  ll a, b, c;
  for (int ca = 1; ca <= caa; ++ca) {
    printf("Case %d: ", ca);
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
      printf("Invalid");
    } else if (a == b && b == c) {
      printf("Equilateral");
    } else if (a == b || b == c || a == c) {
      printf("Isosceles");
    } else {
      printf("Scalene");
    }
    printf("\n");
  }
  return 0;
}
