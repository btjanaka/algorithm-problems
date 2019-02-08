// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11975
#include <bits/stdc++.h>
using namespace std;

int balls[80];
int value[4];
int board[5][5];
bool received[4];

enum values {
  kCorner,
  kMid,
  kDiagonals,
  kTable,
};

int corner_check() {
  return board[0][0] == -1 && board[0][4] == -1 && board[4][0] == -1 &&
         board[4][4] == -1;
}

int midline_check() {
  bool res = true;
  for (int i = 0; i < 5; ++i) {
    res &= board[2][i] == -1;
  }
  return res;
}

int diagonal_check() {
  return board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 &&
         board[3][3] == -1 && board[4][4] == -1 && board[4][0] == -1 &&
         board[3][1] == -1 && board[1][3] == -1 && board[0][4] == -1;
}

int table_check() {
  bool res = true;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      res &= board[i][j] == -1;
    }
  }
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int c = 1; c <= t; ++c) {
    int n, L;
    scanf("%d %d", &n, &L);
    for (int i = 0; i < n; ++i) scanf("%d", &balls[i]);
    for (int i = 0; i < 4; ++i) scanf("%d", &value[i]);

    printf("Case %d:\n", c);

    // Process boards
    for (int ticket = 0; ticket < L; ++ticket) {
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
          scanf("%d", &board[i][j]);
        }
      }

      int money = 0;
      memset(received, 0, sizeof(bool) * 4);
      for (int i = 1; i <= n; ++i) {
        int b = balls[i - 1];
        for (int r = 0; r < 5; ++r) {
          for (int c = 0; c < 5; ++c) {
            if (board[r][c] == b) board[r][c] = -1;
          }
        }
        if (corner_check() && !received[kCorner] && i <= 35) {
          money += value[kCorner];
          received[kCorner] = true;
        }
        if (midline_check() && !received[kMid] && i <= 40) {
          money += value[kMid];
          received[kMid] = true;
        }
        if (diagonal_check() && !received[kDiagonals] && i <= 45) {
          money += value[kDiagonals];
          received[kDiagonals] = true;
        }
        if (table_check() && !received[kTable]) {
          money += value[kTable];
          received[kTable] = true;
        }
      }

      printf("%d\n", money);
    }

    if (c != t) putchar('\n');
  }
  return 0;
}
