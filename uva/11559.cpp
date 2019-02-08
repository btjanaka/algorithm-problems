// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11559
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int b;
  int h;
  int w;
  while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
    int min = 2000000000;
    for (int i = 0; i < h; ++i) {
      int p;
      cin >> p;
      int a;
      for (int j = 0; j < w; ++j) {
        cin >> a;
        if (a >= n && p * n < min && p * n < b) min = p * n;
      }
    }
    if (min == 2000000000)
      printf("stay home\n");
    else
      printf("%d\n", min);
  }
}
