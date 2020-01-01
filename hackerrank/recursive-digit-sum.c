// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) recursive-digit-sum
// Title: Recursive Digit Sum
// Link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
// Idea: Sum the digits until the sum is less than 10.
// Difficulty: easy
// Tags: math
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  long long sum = 0;
  int ch, k;

  // Sum the digits as they come in from the input.
  while ((ch = getchar()) != ' ') sum += ch - '0';
  scanf("%d", &k);
  sum *= k;

  // Keep summing until sum is less than 10.
  while (sum >= 10) {
    long long new_sum = 0;
    // Iterate through the digits.
    for (; sum > 0; sum /= 10) new_sum += sum % 10;
    sum = new_sum;
  }
  printf("%lld\n", sum);
  return 0;
}
