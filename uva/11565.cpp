// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11565
// Source: Competitive Programming 3 pg. 72
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  while (n--) {
    int a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);
    int x, y, z;
    bool sol = false;
    for (x = -100; x <= 100; ++x) {
      for (y = -100; y <= 100; ++y) {
        for (z = -100; z <= 100; ++z) {
          if (y != x && z != y && x != z && x + y + z == a && x * y * z == b &&
              x * x + y * y + z * z == c) {
            if (!sol) {
              printf("%d %d %d\n", x, y, z);
              sol = true;
            }
          }
        }
      }
    }
    if (!sol) printf("No solution.\n");
  }
  return 0;
}
