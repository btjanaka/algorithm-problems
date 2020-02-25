// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) caesar-cipher-1
// Title: Caesar Cipher
// Link: https://www.hackerrank.com/challenges/caesar-cipher-1/problem
// Idea: Implementation
// Difficulty: easy
// Tags: implementation
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k;
  scanf("%d", &n);
  char s[n + 1];
  scanf("%s %d", s, &k);

  for (int i = 0; i < n; ++i) {
    if (isupper(s[i])) {
      s[i] = (s[i] - 'A' + k) % 26 + 'A';
    } else if (islower(s[i])) {
      s[i] = (s[i] - 'a' + k) % 26 + 'a';
    }
  }

  printf("%s", s);

  return 0;
}
