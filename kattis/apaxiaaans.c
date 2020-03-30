// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) apaxiaaans
// Title: Apaxiaaaaaaaaaaaans!
// Link: https://open.kattis.com/problems/apaxiaaans
// Idea: Keep track of the previous letter -- if it is the same, as the current
// one, don't output it.
// Difficulty: easy
// Tags: ad-hoc
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;

int main() {
  int ch;
  int prev = 0;
  while ((ch = getchar()) != -1) {
    if (ch != prev) {
      putchar(ch);
      prev = ch;
    }
  }
  return 0;
}
