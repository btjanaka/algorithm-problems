// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10550
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  while (scanf("%d %d %d %d", &a, &b, &c, &d) && (a || b || c || d)) {
    int sum = 720;
    if (a > b)
      sum += (a - b) * 9;
    else
      sum += (a + 40 - b) * 9;
    sum += 360;  // 1120
    if (c > b)
      sum += (c - b) * 9;  // 1620
    else
      sum += (c + 40 - b) * 9;
    if (c > d)
      sum += (c - d) * 9;  // 1890
    else
      sum += (c + 40 - d) * 9;
    cout << sum << endl;
  }
  return 0;
}