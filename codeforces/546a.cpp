// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeForces) 546a
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int k, n, w;
  while (GET(k) > 0) {
    GET(n);
    GET(w);
    ll tot = w * (w + 1) / 2 * k;
    printf("%lld\n", max(0ll, tot - n));
  }
  return 0;
}
