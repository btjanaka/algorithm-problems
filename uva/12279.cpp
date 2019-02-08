// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12279
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 1; n != 0; ++i) {
    int bal = 0;
    for (int j = 0; j < n; ++j) {
      int k;
      scanf("%d\n", &k);
      if (k == 0)
        --bal;
      else
        ++bal;
    }
    printf("Case %d: %d\n", i, bal);
    scanf("%d\n", &n);
  }
  return 0;
}
