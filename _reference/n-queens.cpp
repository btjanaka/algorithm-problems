// Counts the number of solutions to an n-queens problem of size n.
// Usage:
//   g++ n-queens.cpp && a.out [N]
#include <bits/stdc++.h>
using namespace std;

int total;  // Total positions counted.
int n;      // Board size.

// Recurs through the columns of the board, trying every row in each column.
// The occupied* inputs are variables indicating which rows in the current
// column are attacked. Specifically:
// - occupied_rows indicates which places are attacked along a row.
//     Q ---- X
// - occupied_left_diag indicates which places are attacked along a diagonal
//   from bottom left to top right
//       X
//      /
//     /
//    Q
// - occupied_right_diag indicates which places are attacked along a diagonal
//   from top left to bottom right
//    Q
//     \
//      \
//       X
// As we recur over these columns, each of these bitsets gets modified
// appropriately -- rows stay the same, left_diag shifts left (if a "diagonal"
// queen attacks row x on this column, it attacks row x - 1 on the next column),
// and right_diag shifts right.
void backtrack(int col, int occupied_rows, int occupied_left_diag,
               int occupied_right_diag) {
  // Base case -- reached the end.
  if (col == n) {
    ++total;
    return;
  }

  // pos is a bitset for the current position.
  int row_max = 1 << n;
  for (int pos = 1; pos != row_max; pos <<= 1) {
    // Check if any squares are attacked.
    if (!(pos & occupied_rows) && !(pos & occupied_left_diag) &&
        !(pos & occupied_right_diag)) {
      backtrack(col + 1, occupied_rows | pos, (occupied_left_diag | pos) << 1,
                (occupied_right_diag | pos) >> 1);
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: g++ n-queens.cpp && a.out [N]\n");
    exit(1);
  }

  n = atoi(argv[1]);

  // Time the running.
  clock_t t = clock();
  total = 0;
  backtrack(0, 0, 0, 0);
  t = clock() - t;

  printf("Solutions: %d\n", total);
  printf("Time:      %.6f seconds\n", (float)t / CLOCKS_PER_SEC);

  return 0;
}
