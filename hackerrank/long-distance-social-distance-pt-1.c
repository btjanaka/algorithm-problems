// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) long-distance-social-distance-pt-1
// Title: Long Distance Social Distance 1
// Link:
// https://www.hackerrank.com/contests/uci-ucsd-quarantine-competition/challenges/long-distance-social-distance-pt-1/problem
// Idea: floor(n / 2) rows will have 2 seats each, and ceiling (n / 2) rows will
// have 4 seats each.
// Difficulty: easy
// Tags: math
#include <stdio.h>
#include <stdlib.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (n / 2 + n % 2) * 4 + (n / 2) * 2);
  }
  return 0;
}
