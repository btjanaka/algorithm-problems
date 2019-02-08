// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11001
#include <bits/stdc++.h>
using namespace std;

int main() {
  double v, v0;
  while (scanf("%lf %lf", &v, &v0) && v > 0 && v0 > 0) {
    if (v <= v0) {
      printf("0\n");
      continue;
    }
    double res_len = -1;
    int res = 0;
    double curr_v = v0 + 1;  // Just to pass first check on for loop
    // Keep decreasing curr_v until it reaches v0; at the same time,
    // calculate the current length and change the max as necessary.
    for (int i = 1; curr_v > v0; ++i) {
      curr_v = v / i;
      double curr_len = 0.3 * sqrt(curr_v - v0) * i;
      // Probably not necessary, but always important to give a
      // little margin of error for equality between floating
      // point numbers.
      if (fabs(curr_len - res_len) < 0.000001) goto error;
      if (curr_len > res_len) {
        res_len = curr_len;
        res = i;
      }
    }
    printf("%d\n", res);
    continue;
  error:
    printf("0\n");
  }
  return 0;
}
