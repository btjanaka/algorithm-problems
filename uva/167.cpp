// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 167
// This is a variant of the 8 queens problem that simply involves keeping track
// of a total. Instead of printing the solution, simply add up all the board's
// values and see if it exceeds the current maximum (marked by tot).
#include <bits/stdc++.h>
using namespace std;

int board[8][8];
int tot;
int queens[8];

void backtrack(int c, int rw, int ld, int rd) {
  if (c == 8) {
    // Add up board values and see if max
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
      sum += board[queens[i]][i];
    }
    if (sum > tot) tot = sum;
    return;
  }
  for (int r = 0; r < 8; ++r) {
    int p = 1 << r;
    if (!(p & rw) && !(p & ld) && !(p & rd)) {
      queens[c] = r;
      backtrack(c + 1, rw | p, (ld | p) << 1, (rd | p) >> 1);
    }
  }
}

int main() {
  int k;
  scanf("%d\n", &k);
  while (k--) {
    // Populate board
    memset(board, 0, sizeof board);
    tot = 0;
    for (int x = 0; x < 8; ++x)
      for (int y = 0; y < 8; ++y) scanf("%d", &board[x][y]);

    backtrack(0, 0, 0, 0);
    printf("%5d\n", tot);
  }
  return 0;
}
