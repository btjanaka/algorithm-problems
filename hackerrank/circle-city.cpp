// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) circle-city
// Title: Circle City
// Link: https://www.hackerrank.com/challenges/circle-city/problem
// Idea: We need to find lattice points that are on the edge of the circle. We
// can identify these as points that have whole-number coordinates and are r
// units away from the origin. To find such points, we check all possible x
// coordinates in the range [1,r] and see if y^2 = d^2 - x^2 is a perfect
// square. This will only tell us the number of lattice points in quadrant 1 of
// the circle, so we multiply by 4 and check if the number of stations k is
// enough to cover all the points.
// Difficulty: medium
// Tags: computational-geometry
#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_set<int> squares;
  for (int i = 0; i < 45000; ++i) squares.insert(i * i);

  int t, d, k;
  cin >> t;

  while (t--) {
    cin >> d >> k;
    int r = int(sqrt(d));

    // Find lattice points on the edge of the circle.
    int lattice_pts = 0;
    for (int x = 1; x <= r; ++x) {
      if (squares.find(d - (x * x)) != squares.end()) {
        ++lattice_pts;
      }
    }

    cout << (4 * lattice_pts <= k ? "possible\n" : "impossible\n");
  }

  return 0;
}
