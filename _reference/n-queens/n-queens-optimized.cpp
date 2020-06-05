// Counts the number of solutions to an n-queens problem of size n.
// Usage:
//   make n-queens-optimized
//   n-queens-optimized [N]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <vector>

// See n-queens.cpp for an explanation of this function.
long long backtrack(int occupied_rows, int occupied_left_diag,
                    int occupied_right_diag, const int complete) {
  if (occupied_rows == complete) {
    return 1;
  }

  long long solutions = 0;

  int available_pos =
      complete & ~(occupied_rows | occupied_left_diag | occupied_right_diag);
  while (available_pos) {
    int pos = available_pos & -available_pos;
    available_pos -= pos;
    solutions += backtrack(occupied_rows | pos, (occupied_left_diag | pos) << 1,
                           (occupied_right_diag | pos) >> 1, complete);
  }

  return solutions;
}

// Figures out how to run backtrack() to get the final solution.
long long run_queens(int n) {
  int complete = (1 << n) - 1;

  // Handle the 1st level here so we can go through just half of the
  // solutions; i.e. just the first half of the positions of the 1st queen.
  // We then multiply by 2.
  int num_threads = n / 2 + n % 2;  // We spawn a thread for each 1st queen pos.
  std::vector<std::thread> threads(num_threads);
  std::vector<int> results(num_threads);
  for (int i = 0; i < num_threads; ++i) {
    threads[i] = std::thread([i, complete, &results]() {
      int pos = 1 << i;
      results[i] = backtrack(pos, pos << 1, pos >> 1, complete);
    });
  }

  // Get results from the threads.
  long long total = 0;
  for (int i = 0; i < n / 2; ++i) {
    threads[i].join();
    total += results[i];
  }
  total *= 2;
  // Odd case.
  if (n % 2) {
    threads.back().join();
    total += results.back();
  }

  return total;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: n-queens-optimized [N]\n");
    exit(1);
  }

  // Bitset with first n bits set to 1 (n is board size).
  int n = atoi(argv[1]);

  // Time the running. System time will be longer than wall time because of
  // multithreading.
  auto system_time_start = std::clock();
  auto wall_time_start = std::chrono::system_clock::now();

  long long total = run_queens(n);

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
