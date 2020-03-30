// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) 2048
// Title: 2048
// Link: https://open.kattis.com/problems/2048
// Idea: Implement the game.
// Difficulty: medium
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int b[4][4];

// rotates the board counterclockwise n times
void rotate(int n) {
  for (int _ = 0; _ < n; ++_) {  // haha
    for (int i = 0; i < 2; ++i) {
      for (int j = i; j < (4 - i - 1); ++j) {
        int tmp = b[i][j];
        b[i][j] = b[j][3 - i];
        b[j][3 - i] = b[3 - i][3 - j];
        b[3 - i][3 - j] = b[3 - j][i];
        b[3 - j][i] = tmp;
      }
    }
  }
}

// makes a move in the left direction always
void compress() {
  for (int i = 0; i < 4; ++i) {
    // clear out zeros
    int j2 = 0;
    for (int j = 0; j < 4; ++j) {
      if (b[i][j] != 0) {
        b[i][j2++] = b[i][j];
        if (j != j2 - 1) b[i][j] = 0;
      }
    }

    // clear out duplicates and replace with double and a zero
    int tmp[4] = {0, 0, 0, 0};
    j2 = 0;
    for (int j = 0; j < 4; ++j) {
      if (j != 3 && b[i][j] == b[i][j + 1]) {
        tmp[j] = 2 * b[i][j];
        b[i][j + 1] = 0;
      } else {
        tmp[j] = b[i][j];
      }
    }
    memcpy(b[i], tmp, sizeof(tmp));

    // clear out zeros again
    j2 = 0;
    for (int j = 0; j < 4; ++j) {
      if (b[i][j] != 0) {
        b[i][j2++] = b[i][j];
        if (j != j2 - 1) b[i][j] = 0;
      }
    }
  }
}

int main() {
  int first;
  while (GET(first) > 0) {
    // input board
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (i == 0 && j == 0) {
          b[i][j] = first;
        } else {
          GET(b[i][j]);
        }
      }
    }

    int move;  // 0 = left, 1 = up, 2 = right, 3 = down
    GET(move);
    rotate(move);  // rotate the board to get it to a consistent position for
                   // the move
    compress();
    rotate(4 - move);  // rotate the board back to original position

    // output
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        printf("%d%c", b[i][j], j == 3 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
