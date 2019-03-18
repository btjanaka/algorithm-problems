// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) permuting-two-arrays
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int a[1010], b[1010];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, k;
    GET(n);
    GET(k);
    for (int i = 0; i < n; ++i) GET(a[i]);
    for (int i = 0; i < n; ++i) GET(b[i]);
    sort(a, a + n);
    sort(b, b + n);

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= (a[i] + b[n - i - 1]) >= k;
    }

    printf(ok ? "YES\n" : "NO\n");
  }
  return 0;
}
