// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 113
#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, p;
  while (scanf("%lf %lf", &n, &p) > 0)
    printf("%ld\n", lround(exp(log((double)p) / (double)n)));
  return 0;
}
