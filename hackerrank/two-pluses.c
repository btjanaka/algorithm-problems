// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) two-pluses
// Title: Ema's Supercomputer
// Link: https://www.hackerrank.com/challenges/two-pluses/problem
// Idea: Explore all possible sizes for the first plus, then maximize the size
// of the second plus after the first plus has been marked. It is important to
// recognize that we cannot greedily maximize the size of the first plus.
// Difficulty: medium
// Tags: implementation, array
#include <stdio.h>
#include <stdlib.h>

int N, M;
char G[20][20];

// Try all centers to find the size of the biggest second plus.
int findSecondPlus() {
  int max_size = -1;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      if (G[r][c] == 'B') continue;
      int cur_size = 0;
      while (r + cur_size < N && r - cur_size >= 0 && c + cur_size < M &&
             c - cur_size >= 0 && G[r + cur_size][c] == 'G' &&
             G[r - cur_size][c] == 'G' && G[r][c + cur_size] == 'G' &&
             G[r][c - cur_size] == 'G') {
        ++cur_size;
      }
      --cur_size;
      if (cur_size > max_size) max_size = cur_size;
    }
  }
  return 4 * max_size + 1;
}

// Try all centers and sizes for the first plus.
int findPlus() {
  int max_overall = 0;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      if (G[r][c] == 'B') continue;
      int cur_size = 0;
      while (r + cur_size < N && r - cur_size >= 0 && c + cur_size < M &&
             c - cur_size >= 0 && G[r + cur_size][c] == 'G' &&
             G[r - cur_size][c] == 'G' && G[r][c + cur_size] == 'G' &&
             G[r][c - cur_size] == 'G') {
        // See what product we can achieve in total.

        // Mark the plus as bad.
        G[r + cur_size][c] = G[r - cur_size][c] = G[r][c + cur_size] =
            G[r][c - cur_size] = 'B';

        // Check product.
        int possible_size = findSecondPlus() * (4 * cur_size + 1);
        max_overall = possible_size > max_overall ? possible_size : max_overall;

        ++cur_size;
      }
      // Mark the plus as good again.
      for (int i = 0; i < cur_size; ++i)
        G[r + i][c] = G[r - i][c] = G[r][c + i] = G[r][c - i] = 'G';
    }
  }

  return max_overall;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; ++i) scanf("%s", G[i]);
  printf("%d\n", findPlus());
  return 0;
}
