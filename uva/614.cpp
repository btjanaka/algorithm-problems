// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 614
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int r, c, r0, c0, rf, cf;
int maze[15][15];
int res[15][15];
bool visited[15][15];
bool dfs(int rcur, int ccur, int depth) {
  visited[rcur][ccur] = true;

  if (rcur == rf && ccur == cf) {
    // base case
  } else if (ccur > 0 && maze[rcur][ccur - 1] != 1 &&
             maze[rcur][ccur - 1] != 3 && !visited[rcur][ccur - 1] &&
             dfs(rcur, ccur - 1, depth + 1)) {
    // west
  } else if (rcur > 0 && maze[rcur - 1][ccur] != 2 &&
             maze[rcur - 1][ccur] != 3 && !visited[rcur - 1][ccur] &&
             dfs(rcur - 1, ccur, depth + 1)) {
    // north
  } else if (ccur < c - 1 && maze[rcur][ccur] != 1 && maze[rcur][ccur] != 3 &&
             !visited[rcur][ccur + 1] && dfs(rcur, ccur + 1, depth + 1)) {
    // south
  } else if (rcur < r - 1 && maze[rcur][ccur] != 2 && maze[rcur][ccur] != 3 &&
             !visited[rcur + 1][ccur] && dfs(rcur + 1, ccur, depth + 1)) {
    // east
  } else {
    res[rcur][ccur] = -1;
    return false;
  }
  res[rcur][ccur] = depth;
  return true;
}

void print_header() {
  putchar('+');
  for (int i = 0; i < c; ++i) printf("---+");
  putchar('\n');
}

int main() {
  for (int ca = 1; GET(r) && r; ++ca) {
    // input
    GET(c);
    GET(r0);
    GET(c0);
    GET(rf);
    GET(cf);
    --r0;
    --c0;
    --rf;
    --cf;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        GET(maze[i][j]);
      }
    }

    // calculate
    memset(res, 0, sizeof(res));
    memset(visited, false, sizeof(visited));
    dfs(r0, c0, 1);

    // output
    printf("Maze %d\n\n", ca);
    print_header();
    for (int i = 0; i < r; ++i) {
      // numbers
      putchar('|');
      for (int j = 0; j < c; ++j) {
        switch (res[i][j]) {
          case -1:
            printf("???");
            break;
          case 0:
            printf("   ");
            break;
          default:
            printf("%3d", res[i][j]);
            break;
        }
        putchar((j == c - 1 || maze[i][j] == 1 || maze[i][j] == 3) ? '|' : ' ');
      }
      putchar('\n');

      // divider
      if (i != r - 1) {
        putchar('+');
        for (int j = 0; j < c; ++j) {
          printf((maze[i][j] == 2 || maze[i][j] == 3) ? "---" : "   ");
          putchar('+');
        }
        putchar('\n');
      }
    }
    print_header();
    printf("\n\n");
  }
  return 0;
}
