// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10340
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  string a, b;
  while (cin >> a >> b) {
    int a_i = 0;
    for (int i = 0; a_i < a.size() && i < b.size(); ++i) {
      if (b[i] == a[a_i]) {
        ++a_i;
      }
    }
    if (a_i == a.size()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
