// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 868
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int n;
int m;
int maze[100][100];

// tgt keeps track of the current value we need to find in the sequence - i.e.
// it's 2 when going for 1,2, 3 for 1,2,3, etc.
void backtrack(int tgt, int row, int col, int n, int m, int end[2]) {
  // End case: row is at the bottom
  if (row == n - 1) {
    if (end[1] == -1) {
      end[1] = col;
    } else {
      end[1] = end[1] < col ? end[1] : col;
    }
    return;
  }

  // Determine next values to find
  int next;
  int next_tgt;
  if (maze[row][col] == tgt) {
    next = 1;
    next_tgt = tgt + 1;
  } else {
    next = maze[row][col] + 1;
    next_tgt = tgt;
  }

  // Check 4 surrounding tiles
  if (row < n - 1 && maze[row + 1][col] == next) {
    backtrack(next_tgt, row + 1, col, n, m, end);
  }
  if (row > 0 && maze[row - 1][col] == next) {
    backtrack(next_tgt, row - 1, col, n, m, end);
  }
  if (col < m - 1 && maze[row][col + 1] == next) {
    backtrack(next_tgt, row, col + 1, n, m, end);
  }
  if (col > 0 && maze[row][col - 1] == next) {
    backtrack(next_tgt, row, col - 1, n, m, end);
  }
}

int main() {
  int t;
  GET(t);
  while (t--) {
    GET(n);
    GET(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        GET(maze[i][j]);
      }
    }

    // coordinates stored as row, column
    int start[2];
    start[0] = 0;
    start[1] = -1;

    int end[2];
    end[0] = n - 1;
    end[1] = -1;

    // Generate solutions - after this, the start should have the correct
    // coordinates, and the end should have the correct coordinates.
    // We make sure to check if end[1] is -1 because that indicates if a
    // solution was found. If a solution was already found, we are done because
    // we want to stay with the lexicographically lowest. Sorting between end
    // positions for a given start position is done in backtrack().
    for (int i = 0; end[1] == -1 && i < m; ++i) {
      if (maze[0][i] == 1) {
        start[1] = i;
        backtrack(1, 0, i, n, m, end);
      }
    }

    printf("%d %d\n", start[0] + 1, start[1] + 1);
    printf("%d %d\n", end[0] + 1, end[1] + 1);
    if (t) PLN;
  }
  return 0;
}
