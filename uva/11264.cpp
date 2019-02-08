// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11264
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    int n;
    scanf("%d\n", &n);
    int tot = 0;
    int c1, c2;
    int s = 0;

    scanf("%d", &c1);  // first number

    for (int i = 0; i < n - 1; ++i) {
      scanf("%d", &c2);
      if (c2 > s + c1) {
        ++tot;
        s += c1;
      }
      c1 = c2;
    }
    ++tot;  // for the maximum coin
    printf("%d\n", tot);
  }
  return 0;
}
