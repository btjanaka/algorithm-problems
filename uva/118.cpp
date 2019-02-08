// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 118
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  bool fall[55][55];
  memset(fall, false, sizeof(fall));
  int mx_x, mx_y;
  GET(mx_x);
  GET(mx_y);

  char dir_to_ch[4] = {'N', 'E', 'S', 'W'};
  unordered_map<char, int> ch_to_dir;
  for (int i = 0; i < 4; ++i) ch_to_dir[dir_to_ch[i]] = i;

  int x, y;
  char ch;
  int dir;

  while (GET(x) > 0) {
    GET(y);
    getchar();
    ch = getchar();
    dir = ch_to_dir[ch];

    getchar();
    bool ok = true;
    while ((ch = getchar()) != '\n') {
      if (!ok) continue;
      switch (ch) {
        case 'L':
          if (dir == 0)
            dir = 3;
          else
            --dir;
          break;
        case 'R':
          dir = (dir + 1) % 4;
          break;
        case 'F':
          switch (dir) {
            case 0:
              if (y == mx_y) {
                if (!fall[x][y]) {
                  fall[x][y] = true;
                  ok = false;
                }
              } else {
                ++y;
              }
              break;
            case 1:
              if (x == mx_x) {
                if (!fall[x][y]) {
                  fall[x][y] = true;
                  ok = false;
                }
              } else {
                ++x;
              }
              break;
            case 2:
              if (y == 0) {
                if (!fall[x][y]) {
                  fall[x][y] = true;
                  ok = false;
                }
              } else {
                --y;
              }
              break;
            case 3:
              if (x == 0) {
                if (!fall[x][y]) {
                  fall[x][y] = true;
                  ok = false;
                }
              } else {
                --x;
              }
              break;
          }
      }
    }

    // output
    printf("%d %d %c", x, y, dir_to_ch[dir]);
    if (ok) {
      printf("\n");
    } else {
      printf(" LOST\n");
    }
  }
  return 0;
}
