// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 256
#include <bits/stdc++.h>
using namespace std;

int nums[4][10000];

void precalculate(int num_dig) {
  int i = 0;
  int lim = (int)pow(10, 2 * num_dig);
  int bound = (int)pow(10, num_dig);
  for (int n = 0; n < lim; ++n)
    if ((int)pow((n / bound) + (n % bound), 2) == n) nums[num_dig - 1][i++] = n;
  nums[num_dig - 1][i] = -1;
}

int main() {
  int d;
  for (int i = 1; i <= 4; ++i) precalculate(i);
  while (scanf("%d", &d) > 0) {
    int j = d / 2 - 1;
    for (int i = 0; nums[j][i] != -1; ++i) {
      printf("%0*d\n", d, nums[j][i]);
    }
  }
  return 0;
}
