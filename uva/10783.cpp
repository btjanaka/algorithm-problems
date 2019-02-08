// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10783
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  for (int i = 1; i <= ca; ++i) {
    int a, b;
    GET(a);
    GET(b);
    if (a % 2 == 0) ++a;
    if (b % 2 == 0) --b;
    int res = 0;
    for (int j = a; j <= b; j += 2) res += j;
    printf("Case %d: %d\n", i, res);
  }
  return 0;
}
