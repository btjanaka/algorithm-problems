// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11242
#include <bits/stdc++.h>
using namespace std;

int front[100];
int rear[100];
float ratios[10000];

int main() {
  int f, r;
  while (scanf("%d", &f) && f > 0) {
    scanf("%d", &r);
    for (int i = 0; i < f; ++i) scanf("%d", front + i);
    for (int i = 0; i < r; ++i) scanf("%d", rear + i);
    int ratios_i = 0;
    for (int i = 0; i < f; ++i) {
      for (int j = 0; j < r; ++j) {
        ratios[ratios_i++] = (float)rear[j] / front[i];
      }
    }
    sort(ratios, ratios + ratios_i);

    float max_spread = -1;
    for (int i = 0; i < ratios_i - 1; ++i) {
      float spread = ratios[i + 1] / ratios[i];
      if (spread > max_spread) max_spread = spread;
    }
    printf("%.2f\n", max_spread);
  }
  return 0;
}
