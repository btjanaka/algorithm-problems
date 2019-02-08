// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11849
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n, m;
  while (GET(n) && GET(m) && !(!n && !m)) {
    unordered_set<int> ja;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      ja.insert(x);
    }
    int tot = 0;
    for (int i = 0; i < m; ++i) {
      int x;
      GET(x);
      if (ja.find(x) != ja.end()) ++tot;
    }
    printf("%d\n", tot);
  }
  return 0;
}
