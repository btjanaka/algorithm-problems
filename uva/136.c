/* Author: btjanaka (Bryon Tjanaka) */
/* Problem: (UVa) 136 */
#include <stdio.h>
#include <string.h>
#define MX 1000000000

/* int nums[MX]; */
/* int calc() { */
/*   memset(nums, 0, sizeof(nums)); */
/*   nums[1] = 1; */
/*   for (int i = 2; i < MX; i += 2) nums[i] = 1; */
/*   for (int i = 3; i < MX; i += 3) nums[i] = 1; */
/*   for (int i = 5; i < MX; i += 5) nums[i] = 1; */
/*   for (int i = 1; i < MX; ++i) { */
/*     if (!nums[i]) { */
/*       for (int j = i; j < MX; j += i) { */
/*         nums[j] = 0; */
/*       } */
/*     } */
/*   } */

/*   int cnt = 0; */
/*   for (int i = 0; i < MX; ++i) { */
/*     if (nums[i]) { */
/*       printf("%d %d\n", i, cnt); */
/*       ++cnt; */
/*     } */
/*     if (cnt == 1500) { */
/*       return i; */
/*     } */
/*   } */
/*   return -1; */
/* } */

int main() {
  /* printf("%d\n", calc()); */
  printf("The 1500'th ugly number is 859963392.\n");
  return 0;
}
