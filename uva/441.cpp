// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 441
#include <bits/stdc++.h>
using namespace std;

int nums[20];

int main() {
  int k;
  scanf("%d", &k);
  while (k > 0) {
    for (int i = 0; i < k; ++i) {
      scanf("%d", &nums[i]);
    }

    for (int a = 0; a < k - 5; ++a) {
      for (int b = a + 1; b < k - 4; ++b) {
        for (int c = b + 1; c < k - 3; ++c) {
          for (int d = c + 1; d < k - 2; ++d) {
            for (int e = d + 1; e < k - 1; ++e) {
              for (int f = e + 1; f < k; ++f) {
                printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c],
                       nums[d], nums[e], nums[f]);
              }
            }
          }
        }
      }
    }

    scanf("%d", &k);
    if (k > 0) putchar('\n');
  }
  return 0;
}
