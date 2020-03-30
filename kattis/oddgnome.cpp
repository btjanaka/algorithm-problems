// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) oddgnome
// Title: Odd Gnome
// Link: https://open.kattis.com/problems/oddgnome
// Idea: Iterate through and find the gnome out of order.
// Difficulty: easy
// Tags: greedy
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
  FOR(i, 0, n) {
    int g;
    GET(g);
    int cur, prev;
    bool found = false;
    FOR(i, 0, g) {
      GET(cur);
      if (g == 3 && i == 1) {
        cout << i + 1 << endl;
        found = true;
      }
      if (!found && i >= 1 && i != g - 1) {
        if (cur != prev + 1) {
          cout << i + 1 << endl;
          found = true;
        }
      }
      prev = cur;
    }
  }
  return 0;
}
