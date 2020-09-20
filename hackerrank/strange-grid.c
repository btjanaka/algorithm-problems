// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) strange-grid
// Title: Strange Grid Again
// Link: https://www.hackerrank.com/challenges/strange-grid/problem
// Idea: Fiddle around with the numbers. The column determines the starting
// number, then the row determines that a certain number of 9's will be added,
// and a number of 1's will be added.
// Difficulty: easy
// Tags: math
#include <stdio.h>
#include <stdlib.h>

int main() {
  long long r, c;
  scanf("%lld %lld", &r, &c);
  printf("%lld\n",
         (c - 1) * 2 + (r - r % 2) / 2 * 1 + (r - (1 - r % 2)) / 2 * 9);
  return 0;
}
