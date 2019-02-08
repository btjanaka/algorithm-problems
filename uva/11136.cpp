// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11136
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  while (GET(n) && n) {
    multiset<int> bills;
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
      int c;
      GET(c);
      int x;
      for (int j = 0; j < c; ++j) {
        GET(x);
        bills.insert(x);
      }
      tot += *(--bills.end()) - *bills.begin();
      bills.erase(--bills.end());
      bills.erase(bills.begin());
    }
    printf("%lld\n", tot);
  }
  return 0;
}
