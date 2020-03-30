// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) nastyhacks
// Title: Nasty Hacks
// Link: https://open.kattis.com/problems/nastyhacks
// Idea: Comparisons.
// Difficulty: easy
// Tags: math
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
typedef long long ll;
using namespace std;

int main() {
  int n;
  GET(n);
  while (n--) {
    int r, e, c;
    GET(r);
    GET(e);
    GET(c);
    if (e - c == r) {
      printf("does not matter\n");
    } else if (e - c < r) {
      printf("do not advertise\n");
    } else {
      printf("advertise\n");
    }
  }
  return 0;
}
