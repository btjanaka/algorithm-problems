// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10071
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int v, t;
  while (GET(v) > 0) {
    GET(t);
    if(t) {
      printf("%d\n", (int)(.5 * (2 * t) * (2 * t) * v / t));
    } else {
      printf("0\n");
    }
  }
  return 0;
}
