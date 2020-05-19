// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) manasa-loves-maths
// Title: Manasa Loves Maths
// Link: https://www.hackerrank.com/challenges/manasa-loves-maths/problem
// Idea: A number is divisible by 8 if its last 3 digits are divisible by 8.
// Hence, we just need to check whether any set of 3 digits in the number can be
// rearranged into a number that is divisible by 8.
// Difficulty: medium
// Tags: math, number-theory
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool divby8(char* num, int i, int j, int k) {
  return (((num[i] - '0') * 100) + ((num[j] - '0') * 10) + (num[k] - '0')) %
             8 ==
         0;
}

int main() {
  char num[120];

  int t;
  scanf("%d", &t);
  while (t--) {
    bool ok = false;
    scanf("%s", num);

    int n = strlen(num);

    if (n == 1) {
      // 1 digit case.
      ok = num[0] == '8' || num[0] == '0';
    } else if (n == 2) {
      // 2 digit case.
      ok = ((num[0] - '0') * 10 + (num[1] - '0')) % 8 == 0 ||
           ((num[1] - '0') * 10 + (num[0] - '0')) % 8 == 0;
    } else {
      // 3 digit case.
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (int k = j + 1; k < n; ++k) {
            // Check all permutations of these 3 digits.
            ok = divby8(num, i, j, k) || divby8(num, i, k, j) ||
                 divby8(num, j, i, k) || divby8(num, j, k, i) ||
                 divby8(num, k, i, j) || divby8(num, k, j, i);
            if (ok) goto found;  // Break out of nested loop...
          }
        }
      }
    }
  found:

    printf(ok ? "YES\n" : "NO\n");
  }
  // num[0] = num[1] = num[2] = '0';
  // printf("%d", divby8(num,0,1,2));
  return 0;
}
