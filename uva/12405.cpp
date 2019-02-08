// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12405
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 1; i <= t; ++i) {
    int n;
    scanf("%d\n", &n);
    char buf[150];
    scanf("%s\n", buf);

    int tot = 0;
    int pos = 0;
    while (pos < n) {
      if (buf[pos] == '.') {
        ++tot;
        pos += 3;
      } else {
        pos += 1;
      }
    }

    printf("Case %d: %d\n", i, tot);
  }
  return 0;
}
