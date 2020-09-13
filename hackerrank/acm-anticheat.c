// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) acm-anticheat
// Title: ACM Anticheat
// Link:
// https://www.hackerrank.com/contests/acmxfacebook-competition-2020/challenges/acm-anticheat/problem
// Idea: Store the board members, then check for conflicts when going thru the
// competitors. Store the conflicts so they can be printed out in sorted order.
// Difficulty: easy
// Tags: set, implementation
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 2000200
bool isboard[MAX];
bool isconflict[MAX];

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    isboard[x] = true;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (isboard[x]) {
      isconflict[x] = true;
    }
  }
  bool first = true;
  for (int i = 0; i < MAX; ++i) {
    if (isconflict[i]) {
      if (first) {
        printf("%d", i);
        first = false;
      } else {
        printf(" %d", i);
      }
    }
  }
  printf("\n");
  return 0;
}
