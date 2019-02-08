/* Author: btjanaka (Bryon Tjanaka) */
/* Problem: (UVa) 674 */
#include <stdio.h>
#define GET(x) scanf("%d", &x)

static int dp[8000];

int main() {
  register int i, j;
  int c[5] = {50, 25, 10, 5, 1};
  dp[0] = 1;
  for (j = 0; j < 5; ++j) {
    for (i = c[j]; i <= 8000; ++i) {
      dp[i] += dp[i - c[j]];
    }
  }
  int n;
  while (GET(n) > 0) {
    printf("%d\n", dp[n]);
  }
  return 0;
}
