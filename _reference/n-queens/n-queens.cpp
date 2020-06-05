// Counts the number of solutions to an n-queens problem of size n.
// Usage:
//   make n-queens
//   n-queens [N]
#include <bits/stdc++.h>
using namespace std;

// Recurs through the columns of the board, trying every row in each column.
// The occupied* inputs are variables indicating which rows in the current
// column are attacked. Specifically:
// - occupied_rows indicates which places are attacked along a row.
//     Q ---- X
// - occupied_left_diag indicates which places are attacked along a diagonal
//   from bottom left to top right
//   |    X |
//   |   /  |
//   |  /   |
//   | Q    |
// - occupied_right_diag indicates which places are attacked along a diagonal
//   from top left to bottom right
//   | Q    |
//   |  \   |
//   |   \  |
//   |    X |
// As we recur over these columns, each of these bitsets gets modified
// appropriately -- rows stay the same, left_diag shifts left (if a "diagonal"
// queen attacks row x on this column, it attacks row x - 1 on the next column),
// and right_diag shifts right.
long long backtrack(int occupied_rows, int occupied_left_diag,
                    int occupied_right_diag, const int complete) {
  // Base case -- reached the end.
  if (occupied_rows == complete) {
    return 1;  // 1 solution found.
  }

  long long solutions = 0;

  // Holds all available spots as a bitset.
  int available_pos =
      complete & ~(occupied_rows | occupied_left_diag | occupied_right_diag);
  while (available_pos) {
    // Least significant bit to extract an available position.
    int pos = available_pos & -available_pos;
    available_pos -= pos;
    solutions += backtrack(occupied_rows | pos, (occupied_left_diag | pos) << 1,
                           (occupied_right_diag | pos) >> 1, complete);
  }

  return solutions;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: n-queens [N]\n");
    exit(1);
  }

  // Bitset with first n bits set to 1 (n is board size).
  int complete = (1 << atoi(argv[1])) - 1;

  // Time the running.
  auto system_time_start = std::clock();
  auto wall_time_start = std::chrono::system_clock::now();

  long long total = backtrack(0, 0, 0, complete);

  double system_time =
      double(std::clock() - system_time_start) / CLOCKS_PER_SEC;
  double wall_time = std::chrono::duration<double>(
                         std::chrono::system_clock::now() - wall_time_start)
                         .count();

  printf("Solutions  : %lld\n", total);
  printf("System Time: %.9lf seconds\n", system_time);
  printf("Wall Time  : %.9lf seconds\n", wall_time);

  return 0;
}
