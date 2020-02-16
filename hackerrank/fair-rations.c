// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) fair-rations
// Title: Fair Rations
// Link: https://www.hackerrank.com/challenges/fair-rations/problem
// Idea: We know that all people have to have an even number of loaves, so we
// go through the array and add if the person has an odd number of loaves. If
// the last person ends up with an odd number of loaves, the task is impossible.
// Difficulty: easy
// Tags: array
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  // Go through the array, keeping in mind whether we added to the previous
  // person.
  bool added = false;
  int loaves = 0;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);

    // If we added to the previous person, we have to add to this person too.
    if (added) {
      ++x;
      added = false;
    }

    // Check if the last item is odd.
    if (i == n - 1) {
      if (x & 1) ok = false;
      break;
    }

    // Add loaves if the person has an odd number of loaves.
    if (x & 1) {
      added = true;
      loaves += 2;
    }
  }

  // Output.
  if (ok) {
    printf("%d\n", loaves);
  } else {
    printf("NO\n");
  }

  return 0;
}
