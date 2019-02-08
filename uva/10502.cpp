// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10502
#include <bits/stdc++.h>
using namespace std;

int board[110][110];
bool valid[110][110];

int main() {
  int n, m;
  while (scanf("%d", &n) && n > 0) {
    // Input along with:
    // 2d ranged sum (DP) - calculate number of 1's - later on, we can get back
    // the number of 1's and check if it is equal to the area - if so, the
    // rectangle is valid
    scanf("%d", &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%1d", &board[i][j]);
        if (i > 0)
          board[i][j] += board[i - 1][j];  // Add the rectangle from the top
        if (j > 0)
          board[i][j] += board[i][j - 1];  // Add the rectangle from the left
        if (i > 0 && j > 0) board[i][j] -= board[i - 1][j - 1];
      }
    }

    // Processing
    // Check number of one's in rectangles of each dimension starting at each
    // point
    int tot = 0;
    for (int w = 1; w <= n; ++w) {
      for (int h = 1; h <= m; ++h) {
        int area = w * h;
        for (int r = w - 1; r < n; ++r) {
          for (int c = h - 1; c < m; ++c) {
            int r0 = r - w + 1;
            int c0 = c - h + 1;
            int ones = board[r][c];
            if (r0 > 0) ones -= board[r0 - 1][c];
            if (c0 > 0) ones -= board[r][c0 - 1];
            if (r0 > 0 && c0 > 0) ones += board[r0 - 1][c0 - 1];
            if (ones == area) ++tot;
            // printf("w: %d h: %d r: %d c: %d res: %d\n", w, h, r, c, ones ==
            // area);
          }
        }
      }
    }

    // Output
    printf("%d\n", tot);
  }
  return 0;
}
