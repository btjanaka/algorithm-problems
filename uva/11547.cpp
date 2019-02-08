// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11547
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);

  while (t--) {
    long long n;
    scanf("%lld\n", &n);
    n *= 63;
    n += 7492;
    n *= 5;
    n -= 498;
    printf("%lld\n", abs((n / 10) % 10));
  }

  return 0;
}
