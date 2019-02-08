// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 573
#include <bits/stdc++.h>
using namespace std;
int main() {
  while (true) {
    int d, f;
    float h, u;
    cin >> h >> u >> d >> f;
    if (!h) break;

    float tot = 0;
    float fatigue = 0.01 * f * u;
    tot += u;
    int day = 1;
    while (tot <= h && tot >= 0) {
      // printf("d: %d u: %.2f f: %d h: %.2f fatigue: %.2f tot: %.2f\n",
      // d,u,f,h,fatigue,tot);
      tot -= d;
      if (tot < 0) break;
      u -= fatigue;
      if (u < 0) u = 0;
      tot += u;
      ++day;
    }
    if (tot > h)
      printf("success on day %d\n", day);
    else
      printf("failure on day %d\n", day);
  }
  return 0;
}
