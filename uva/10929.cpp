// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10929
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  string s;
  while (getline(cin, s) && s != "0") {
    bool ok = true;
    if (s.size() == 1) {
      ok = false;
    } else {
      int carry = 0;
      for (int i = 0; i < s.size(); ++i) {
        int cur = carry * 10 + (s[i] - '0');
        carry = cur % 11;
      }
      ok = carry == 0;
    }

    if (ok) {
      printf("%s is a multiple of 11.\n", s.c_str());
    } else {
      printf("%s is not a multiple of 11.\n", s.c_str());
    }
  }
  return 0;
}
