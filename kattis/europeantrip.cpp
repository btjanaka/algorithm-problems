// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) europeantrip
#include <bits/stdc++.h>
using namespace std;
// Original Source:
// https://stackoverflow.com/questions/12934213/how-to-find-out-geometric-median

// given a point (x, y) on a grid, we can find its left/right/up/down neighbors
// by using these constants: (x + dx[0], y + dy[0]) = upper neighbor etc.
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const double eps = 0.000001;

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
};

// points in the triangle
point a[3];

// finds the sum of (euclidean) distances from each input point to (x, y)
double dist(double x, double y) {
  double ret = 0;

  for (int i = 0; i < 3; ++i) {
    double dx = a[i].x - x;
    double dy = a[i].y - y;

    ret += sqrt(dx * dx + dy * dy);  // classical distance formula
  }

  return ret;
}

// implements the solving algorithm
point solve() {
  // final coordinates - start at COG to make it easier
  double x = (a[0].x + a[1].x + a[2].x) / 3.0,
         y = (a[0].y + a[1].y + a[2].y) / 3.0;

  // start by finding the sum of distances to the center of gravity
  double d = dist(x, y);

  // our step value, chosen by experimentation
  double step = 100.0;

  // done is used to keep track of updates: if none of the neighbors of the
  // current point that are *step* steps away improve the solution, then *step*
  // is too big and we need to look closer to the current point, so we must half
  // *step*.
  int done = 0;

  // while we still need a more precise answer
  while (step > eps) {
    done = 0;
    for (int i = 0; i < 4; ++i) {
      // check the neighbors in all 4 directions.
      double nx = x + step * dx[i];
      double ny = y + step * dy[i];

      // find the sum of distances to each neighbor
      double t = dist(nx, ny);

      // if a neighbor offers a better sum of distances
      if (t < d) {
        // update minimum
        d = t;
        x = nx;
        y = ny;

        // an improvement has been made, so
        // don't half step in the next iteration, because we might need
        // to jump the same amount again
        done = 1;
        break;
      }
    }

    // half the step size, because no update has been made, so we might have
    // jumped too much, and now we need to head back some.
    if (!done) step /= 2;
  }
  return point(x, y);
}

int main() {
  for (int i = 0; i < 3; ++i) {
    scanf("%lf %lf", &a[i].x, &a[i].y);
  }
  point res = solve();
  printf("%.9lf %.9lf\n", res.x, res.y);
  return 0;
}
