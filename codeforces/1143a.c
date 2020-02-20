// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeForces) 1143a
// Title: The Doors
// Link: https://codeforces.com/contest/1143/problem/A
// Idea: Count how many of each door there is, then go through the doors until
// we find that we covered a sufficient number of left exit or right exit doors.
// Difficulty: easy
// Tags: implementation, array
#include <stdio.h>
#include <stdlib.h>

int doors[200200];

int main() {
  int n;
  while (scanf("%d", &n) > 0) {
    // Count up left and right exit doors.
    int left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", doors + i);
      if (doors[i])
        ++right;
      else
        ++left;
    }

    // Find how many doors need to be opened before we find all |left| or
    // |right| doors.
    int k;
    int cur_left = 0, cur_right = 0;
    for (k = 1; k <= n; ++k) {
      if (doors[k - 1]) {
        ++cur_right;
      } else {
        ++cur_left;
      }
      if (cur_right == right || cur_left == left) break;
    }
    printf("%d\n", k);
  }
  return 0;
}
