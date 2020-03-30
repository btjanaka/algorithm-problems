// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) matrix
// Title: Matrix Inverse
// Link: https://open.kattis.com/problems/matrix
// Idea: Find out how to calculate the inverse of a 2x2 matrix.
// Difficulty: easy
// Tags: math
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int a, b, c, d;
  for (int ca = 1; scanf("%d %d %d %d", &a, &b, &c, &d) > 0; ++ca) {
    int det = a * d - b * c;
    printf("Case %d:\n%d %d\n%d %d\n", ca, d / det, -b / det, -c / det,
           a / det);
  }
  return 0;
}
