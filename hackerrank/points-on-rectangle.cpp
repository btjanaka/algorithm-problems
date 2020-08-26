// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) points-on-rectangle
// Title: Points on a Rectangle
// Link: https://www.hackerrank.com/challenges/points-on-rectangle/problem
// Idea: Find the min and max x and y values. If the points lie on a rectangle,
// then every point should have an x-coordinate equal to the min or max x, and a
// y-coordinate equal to the min or max y.
// Difficulty: easy
// Tags: geometry
#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int n;
    cin >> n;

    // Input the points and store the min and max x- and y-values.
    vector<int> xs, ys;
    int x_min = INT_MAX, x_max = INT_MIN, y_min = INT_MAX, y_max = INT_MIN;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      x_min = min(x, x_min);
      x_max = max(x, x_max);
      y_min = min(y, y_min);
      y_max = max(y, y_max);
      xs.push_back(x);
      ys.push_back(y);
    }

    // Figure out whether all the points lie on the rectangle.
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (!(xs[i] == x_min || xs[i] == x_max || ys[i] == y_min ||
            ys[i] == y_max)) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
