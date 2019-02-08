// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12372
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);

  for (int i = 1; i <= t; ++i) {
    int x, y, z;
    scanf("%d %d %d\n", &x, &y, &z);
    if (x > 20 || y > 20 || z > 20)
      printf("Case %d: bad\n", i);
    else
      printf("Case %d: good\n", i);
  }

  return 0;
}
