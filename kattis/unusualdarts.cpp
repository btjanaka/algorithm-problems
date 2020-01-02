// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) unusualdarts
// Title: Unusual Darts
// Link: https://open.kattis.com/problems/unusualdarts
// Idea: Try all orderings of points and see which one matches the area most
// closely. Make sure that the polygon is simple before checking the
// probability, and keep in mind that there are 3 darts.
// Difficulty: medium
// Tags: computational-geometry
#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x;
  double y;
};

bool onSegment(Point p, Point q, Point r) {
  return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
         q.y >= min(p.y, r.y);
}

int orientation(Point p1, Point p2, Point p3) {
  double det = p1.x * p2.y - p2.x * p1.y + p3.x * p1.y - p1.x * p3.y +
               p2.x * p3.y - p3.x * p2.y;
  if (abs(det) < 1e-7) return 0;
  if (det < 0.0) return -1;
  if (det > 0.0) return 1;
}

bool intersect(Point p1, Point q1, Point p2, Point q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (((o1 > 0 && o2 < 0) || (o1 < 0 && o2 > 0)) &&
      ((o3 > 0 && o4 < 0) || (o3 < 0 && o4 > 0)))
    return true;

  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;

  return false;
}

// Checks all pairs of sides (except those that are already connected) and sees
// if they intersect -- if they do, this is not a simple polygon.
bool isSimple(const array<Point, 7>& polygon, const array<int, 7>& idx) {
  for (int i = 0; i < 7; ++i) {
    for (int j = i + 2; j < 7; ++j) {
      if (i == 0 && j == 6) continue;
      if (intersect(polygon[idx[i]], polygon[idx[(i + 1) % 7]], polygon[idx[j]],
                    polygon[idx[(j + 1) % 7]])) {
        return false;
      }
    }
  }
  return true;
}

// Calculates whether the probability of Bob winning with the given arrangement
// is within the necessary error bounds.
bool areaProbability(const array<Point, 7>& polygon, const array<int, 7>& idx,
                     double p) {
  double area = 0.0, x1, x2, y1, y2;
  for (int i = 0; i < 7; ++i) {
    x1 = polygon[idx[i]].x, x2 = polygon[idx[(i + 1) % 7]].x,
    y1 = polygon[idx[i]].y, y2 = polygon[idx[(i + 1) % 7]].y,
    area += (x1 * y2 - x2 * y1);
  }
  area = fabs(area) / 2.0;

  if (abs(pow(area / 4.0, 3.0) - p) < 1e-5) return true;
  return false;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    // Input
    array<Point, 7> pts;
    for (int i = 0; i < 7; ++i) cin >> pts[i].x >> pts[i].y;
    double p;
    cin >> p;

    // Check all orderings of points.
    array<int, 7> idx;
    iota(idx.begin(), idx.end(), 0);
    bool found = false;
    if (isSimple(pts, idx) && areaProbability(pts, idx, p)) found = true;
    while (!found && next_permutation(idx.begin(), idx.end())) {
      if (isSimple(pts, idx) && areaProbability(pts, idx, p)) found = true;
    }

    // Output
    for (int i = 0; i < 7; ++i) cout << idx[i] + 1 << (i == 6 ? '\n' : ' ');
  }

  return 0;
}
