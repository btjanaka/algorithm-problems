// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10976
#include <bits/stdc++.h>
using namespace std;

// Note that y can be at most 2 * k; beyond that, we start to run into repeats.
// The final solution for each problem will hence be 1 / k = 1 / 2k + 1 / 2k.
// Also note that y must be at least k+1.
//
// Thus, all we need to do is go through all y from k+1 to 2k and find
// the corresponding value. We can isolate x in the formula to get
// x = ky / (y-k); we can check if ky and y-k are divisible by checking if
// ky % (y-k) == 0.

int res[10010][5000][2];  // Each k row stores the x and y for that k
int length[10010];

void precalculate() {
  for (int k = 1; k <= 10000; ++k) {
    int i = 0;
    for (int y = k + 1; y <= 2 * k; ++y) {
      if ((k * y) % (y - k) == 0) {
        int x = (k * y) / (y - k);
        res[k][i][0] = x;
        res[k][i][1] = y;
        ++i;
      }
    }
    res[k][i][0] = res[k][i][1] = -1;
    length[k] = i;
  }
}

int main() {
  int k;
  precalculate();
  while (scanf("%d", &k) > 0) {
    printf("%d\n", length[k]);
    for (int i = 0; i < length[k]; ++i) {
      printf("1/%d = 1/%d + 1/%d\n", k, res[k][i][0], res[k][i][1]);
    }
  }
  return 0;
}
