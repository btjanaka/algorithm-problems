// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1260
#include <bits/stdc++.h>
using namespace std;

int nums[1000000];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    for (int i = 1; i < n; ++i) {
      for (int k = 0; k < i; ++k) {
        if (nums[k] <= nums[i]) ++tot;
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
