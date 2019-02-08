// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 494
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  string s;
  while (getline(cin, s)) {
    int res = 0;
    int i = 0;
    while (i < s.size()) {
      while (i < s.size() && !isalpha(s[i])) {
        ++i;
      }
      bool ok = false;
      while (i < s.size() && isalpha(s[i])) {
        ok = true;
        ++i;
      }
      if (ok) ++res;
    }
    printf("%d\n", res);
  }
  return 0;
}
