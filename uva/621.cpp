// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 621
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);
  char buf[300];

  while (t--) {
    scanf("%s\n", buf);
    if (!(strcmp(buf, "1") && strcmp(buf, "4") && strcmp(buf, "78"))) {
      printf("+\n");  // positive result
    } else if (strncmp(buf + strlen(buf) - 2, "35", 2) == 0) {
      printf("-\n");  // negative result
    } else if (buf[0] == '9' && buf[strlen(buf) - 1] == '4') {
      printf("*\n");  // failed experiment
    } else {
      printf("?\n");  // not completed expeirment
    }
  }
  return 0;
}
