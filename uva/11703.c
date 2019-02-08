/* Author: btjanaka (Bryon Tjanaka) */
/* Problem: (UVa) 11703 */
#include <math.h>
#include <stdio.h>
#define GET(x) scanf("%d", &x)

int x[1000001];

int main() {
  register int i;
  int j;
  x[0] = 1;
  for (i = 1; i <= 1000000; ++i) {
    int isqrt = (int)(floor((double)i - sqrt(i)));
    int ilog = (int)(floor(log((double)i)));
    int isin = (int)(floor((double)i * sin(i) * sin(i)));
    x[i] = (x[isqrt] + x[ilog] + x[isin]) % 1000000;
  }
  while (GET(j) && j != -1) printf("%d\n", x[j]);
  return 0;
}
