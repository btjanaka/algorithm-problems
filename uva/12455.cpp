// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12455
#include <bits/stdc++.h>
using namespace std;

int bars[25];

int main() {
  int t, n, p;
  scanf("%d\n", &t);
  while (t--) {
    scanf("%d\n%d\n", &n, &p);
    for (int i = 0; i < p; ++i) scanf("%d", &bars[i]);

    // This part iterates through all 2^n subsets of the set of bars. This
    // is done by running i from 0 to 2^n - 1. As i increases, it creates
    // all possible combinations of bits, representing which bars to use for
    // that iteration.
    // Source: Competitive Programming 3 pg 73
    bool found = false;
    for (int i = 0; i < (1 << p); ++i) {
      int sum = 0;
      for (int j = 0; j < p; ++j)  // Check which bars to add to the sum
        if (i & (1 << j)) sum += bars[j];
      if (sum == n) {
        found = true;
        break;
      }
    }
    if (found)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
