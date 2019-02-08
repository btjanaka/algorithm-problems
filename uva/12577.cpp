// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12577
#include <bits/stdc++.h>
using namespace std;

int main() {
  char buf[100];
  scanf("%s\n", buf);
  for (int i = 1; strcmp(buf, "*") != 0; ++i) {
    if (strcmp(buf, "Hajj") == 0) {
      printf("Case %d: Hajj-e-Akbar\n", i);
    } else {
      printf("Case %d: Hajj-e-Asghar\n", i);
    }
    scanf("%s\n", buf);
  }
  return 0;
}
