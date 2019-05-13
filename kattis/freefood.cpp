// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) freefood
// Title: Free Food
// Link: https://open.kattis.com/problems/freefood
// Idea: Store an array telling if each day has free food and mark the days as
// you go through the input.
// Difficulty: easy
// Tags: arrays
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

bool serve[366];

int main() {
  int n;
  while (GET(n) > 0) {
    memset(serve, false, sizeof(serve));
    for (int i = 0; i < n; ++i) {
      int s, t;
      GET(s);
      GET(t);
      for (int j = s; j <= t; ++j) {
        serve[j] = true;
      }
    }

    printf("%d\n", accumulate(serve + 1, serve + 366, 0));
  }
  return 0;
}
