// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 458
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    transform(s.begin(), s.end(), s.begin(), [](char c) { return c - 7; });
    cout << s << endl;
  }
  return 0;
}
