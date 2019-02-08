// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11350
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  getchar();
  while (ca--) {
    pair<ll, ll> l = {0, 1}, cur = {1, 1}, r = {1, 0};
    char ch;
    while ((ch = getchar()) != '\n') {
      if (ch == 'L') {
        r = cur;
      } else {
        l = cur;
      }
      cur = {l.first + r.first, l.second + r.second};
    }
    printf("%lld/%lld\n", cur.first, cur.second);
  }
  return 0;
}
