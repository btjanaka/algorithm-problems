// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 146
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  char buf[60];
  while (scanf("%s", buf) && buf[0] != '#') {
    int len = strlen(buf);
    if (next_permutation(buf, buf + len)) {
      printf("%s\n", buf);
    } else {
      printf("No Successor\n");
    }
  }
  return 0;
}
