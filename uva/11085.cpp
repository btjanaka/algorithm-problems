// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11085
#include <bits/stdc++.h>
using namespace std;

int queens[8];
int set_queens[8];
int tot;

void backtrack(int c, int rw, int ld, int rd) {
  if (c == 8) {
    // Count number of queens that are in different position
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
      if (queens[i] != set_queens[i]) ++sum;
    }
    if (sum < tot) tot = sum;  // Set minimum
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
  for (int i = 1;
       scanf("%d %d %d %d %d %d %d %d\n", &set_queens[0], &set_queens[1],
             &set_queens[2], &set_queens[3], &set_queens[4], &set_queens[5],
             &set_queens[6], &set_queens[7]) > 0;
       ++i) {
    for (int i = 0; i < 8; ++i) set_queens[i]--;
    tot = 12;
    backtrack(0, 0, 0, 0);
    printf("Case %d: %d\n", i, tot);
  }
  return 0;
}
