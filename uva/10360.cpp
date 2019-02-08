// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10360
#include <bits/stdc++.h>
using namespace std;

int kills[1025][1025];

int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    for (int i = 0; i < 1025; ++i)
      for (int j = 0; j < 1025; ++j) kills[i][j] = 0;
    int d;
    scanf("%d\n", &d);
    int n;
    scanf("%d\n", &n);

    // Populate board with kills
    int a, b, c;
    while (n--) {
      scanf("%d %d %d\n", &a, &b, &c);
      for (int x = a - d; x <= a + d; ++x)
        for (int y = b - d; y <= b + d; ++y)
          if (x >= 0 && x <= 1024 && y >= 0 && y <= 1024) kills[x][y] += c;
    }
    // for(int x = 0; x < 1025; ++x) {
    // for(int y = 0; y < 1025; ++y) {
    // printf("%d ", kills[x][y]);
    //}
    // putchar('\n');
    //}

    // Find most kills - have to iterate from bottom right to top left to
    // get minimum x and minimum y
    int mx, my;
    int max = -1;
    for (int x = 1024; x >= 0; --x) {
      for (int y = 1024; y >= 0; --y) {
        if (kills[x][y] >= max) {
          max = kills[x][y];
          mx = x;
          my = y;
        }
      }
    }
    printf("%d %d %d\n", mx, my, max);
  }
  return 0;
}
