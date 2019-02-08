// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11078
#include <bits/stdc++.h>
using namespace std;

// Formula:
// max_diff = max(max(a[0..j-1]-a[j])

int nums[100010];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    // Input
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", nums + i);

    // Keep track of current maximum and maximum difference
    int mx = -1000000000;
    int maxdiff = -1000000000;
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] > mx) mx = nums[i];
      int diff = mx - nums[i + 1];
      if (diff > maxdiff) maxdiff = diff;
    }
    printf("%d\n", maxdiff);
  }
  return 0;
}
