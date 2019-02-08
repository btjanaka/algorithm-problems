// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 927
#include <bits/stdc++.h>
using namespace std;

int deg;
int poly[25];
int d, k;

int main() {
  int c;
  scanf("%d\n", &c);
  while (c--) {
    scanf("%d", &deg);
    for (int i = 0; i <= deg; ++i) scanf("%d", &poly[i]);
    scanf("%d %d", &d, &k);

    // Simply run through the values -- input is small enough for us to be
    // dumb.
    long long val = 0;
    long long counter = 0;
    for (long long i = 1; true; ++i) {
      val = i;
      for (long long j = 0; j < i * d; ++j) {
        ++counter;
        if (counter == k) goto done;  // https://xkcd.com/292
      }
    }
  done:

    // Calculate final result
    long long res = 0;
    for (int i = 0; i <= deg; ++i)
      res += poly[i] * (long long)pow((double)val, i);
    printf("%lld\n", res);
  }
  return 0;
}
