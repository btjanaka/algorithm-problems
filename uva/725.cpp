// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 725
// Source: Competitive Programming 3 pg. 71
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  while (n > 0) {
    bool has_sol = false;
    for (int fghij = 1234; fghij <= 98765 / n; ++fghij) {
      int abcde = fghij * n;
      int tmp, used = (fghij < 10000);  // Mark a 0 digit in f
      // used is a bitmap that keeps track of which digits are in the
      // numbers. We don't care about unmarking digits that are repeated
      // because if there is a repeated digit, there must be another digit
      // that is not used.
      tmp = abcde;
      while (tmp) {
        used |= (1 << (tmp % 10));
        tmp /= 10;
      }
      tmp = fghij;
      while (tmp) {
        used |= (1 << (tmp % 10));
        tmp /= 10;
      }
      if (used == (1 << 10) - 1) {  // Check if all digits have been used
        printf("%05d / %05d = %d\n", abcde, fghij, n);
        has_sol = true;
      }
    }
    if (!has_sol) printf("There are no solutions for %d.\n", n);

    scanf("%d\n", &n);
    if (n > 0) putchar('\n');
  }
  return 0;
}
