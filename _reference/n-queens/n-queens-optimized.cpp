// Counts the number of solutions to an n-queens problem of size n.
// Usage:
//   g++ n-queens-optimized.cpp && a.out [N]
#include <bits/stdc++.h>
using namespace std;

// See n-queens.cpp for an explanation of this function.
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
    printf("Usage: g++ n-queens-optimized.cpp && a.out [N]\n");
    exit(1);
  }

  // Bitset with first n bits set to 1 (n is board size).
  int n = atoi(argv[1]);
  int complete = (1 << n) - 1;

  // Time the running.
  clock_t t = clock();

  // Handle the first level here so we can go through just half of the
  // solutions; i.e. just the first half of the positions of the first queen. We
  // then multiply by 2.
  long long total = 0;
  for (int i = 0; i < n / 2; ++i) {
    int pos = 1 << i;
    total += backtrack(pos, pos << 1, pos >> 1, complete);
  }
  total *= 2;

  // Odd case -- calculate for the middle row.
  if (n & 1) {
    int pos = 1 << (n / 2 + 1);
    total += backtrack(pos, pos << 1, pos >> 1, complete);
  }

  t = clock() - t;

  printf("Solutions: %lld\n", total);
  printf("Time:      %.6f seconds\n", (float)t / CLOCKS_PER_SEC);

  return 0;
}
