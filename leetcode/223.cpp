// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 223
// Title: Rectangle Area
// Link: https://leetcode.com/problems/rectangle-area/
// Idea: Compute the intersection along the x and y axes individually, then
// multiply the intersections to get the area of the rectangle intersection.
// Subtract this from the sum of the area of A and B.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int intersect(int a1, int a2, int b1, int b2) {
    if (b1 >= a1 && b2 <= a2) {
      // b is inside of a.
      return b2 - b1;
    } else if (a1 >= b1 && a2 <= b2) {
      // a is inside of b.
      return a2 - a1;
    } else {
      int x1 = b2 - a1;
      int x2 = a2 - b1;
      if (x1 > 0 && x2 > 0) {
        return min(x1, x2);
      } else {
        return 0;
      }
    }
  }

  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int areaA = (ay2 - ay1) * (ax2 - ax1);
    int areaB = (by2 - by1) * (bx2 - bx1);

    int interX = intersect(ax1, ax2, bx1, bx2);
    int interY = intersect(ay1, ay2, by1, by2);

    return areaA + areaB - (interX * interY);
  }
};
