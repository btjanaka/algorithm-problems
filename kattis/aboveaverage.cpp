// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) aboveaverage
// Title: Above Average
// Link: https://open.kattis.com/problems/aboveaverage
// Idea: Calculate the average, and count the students who have more points than
// the average.
// Difficulty: easy
// Tags: math, implementation
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define GET(x) scanf("%d", &x)
using namespace std;

double scores[1010];

int main() {
  int c;
  GET(c);
  while (c--) {
    int n;
    GET(n);
    double avg = 0;
    FOR(i, 0, n) {
      scanf("%lf", &scores[i]);
      avg += scores[i];
    }
    avg /= (double)n;
    int above = 0;
    FOR(i, 0, n) {
      if (scores[i] > avg) ++above;
    }
    printf("%.3lf%%\n", (double)above / n * 100.0);
  }
  return 0;
}
