// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12403
#include <bits/stdc++.h>

using namespace std;

int main() {
  char buf[100];
  int t;
  scanf("%d\n", &t);
  long long tot = 0;
  while (t--) {
    fgets(buf, 100, stdin);
    *strrchr(buf, '\n') = 0;
    if (buf[0] == 'd') {
      tot += atol(buf + 7);
    } else {
      printf("%lld\n", tot);
    }
  }
  return 0;
}
