// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11799
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int max = -1;
    char ch = 0;
    while (ch != '\n') {
      int val;
      cin >> val;
      if (val > max) max = val;
      ch = getchar();
    }
    printf("Case %d: %d\n", i, max);
  }
  return 0;
}
