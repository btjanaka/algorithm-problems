// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11507
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const char *RES[] = {"+x", "-x", "+y", "-y", "+z", "-z"};
enum dir {
  xplus,
  xminus,
  yplus,
  yminus,
  zplus,
  zminus,
};

int main() {
  int L;
  scanf("%d\n", &L);
  char buf[5];

  while (L > 0) {
    enum dir d = xplus;
    for (int i = 0; i < L - 1; ++i) {
      scanf("%s", buf);
      if (strcmp(buf, "+y") == 0) {
        switch (d) {
          case xplus:
            d = yplus;
            break;
          case xminus:
            d = yminus;
            break;
          case yplus:
            d = xminus;
            break;
          case yminus:
            d = xplus;
            break;
          case zplus:
            d = zplus;
            break;
          case zminus:
            d = zminus;
            break;
        }
      } else if (strcmp(buf, "-y") == 0) {
        switch (d) {
          case xplus:
            d = yminus;
            break;
          case xminus:
            d = yplus;
            break;
          case yplus:
            d = xplus;
            break;
          case yminus:
            d = xminus;
            break;
          case zplus:
            d = zplus;
            break;
          case zminus:
            d = zminus;
            break;
        }
      } else if (strcmp(buf, "+z") == 0) {
        switch (d) {
          case xplus:
            d = zplus;
            break;
          case xminus:
            d = zminus;
            break;
          case yplus:
            d = yplus;
            break;
          case yminus:
            d = yminus;
            break;
          case zplus:
            d = xminus;
            break;
          case zminus:
            d = xplus;
            break;
        }
      } else if (strcmp(buf, "-z") == 0) {
        switch (d) {
          case xplus:
            d = zminus;
            break;
          case xminus:
            d = zplus;
            break;
          case yplus:
            d = yplus;
            break;
          case yminus:
            d = yminus;
            break;
          case zplus:
            d = xplus;
            break;
          case zminus:
            d = xminus;
            break;
        }
      }
    }

    printf("%s\n", RES[d]);

    scanf("%d\n", &L);
  }

  return 0;
}
