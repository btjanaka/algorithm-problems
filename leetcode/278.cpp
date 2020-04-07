// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 278
// Title: First Bad Version
// Link: https://leetcode.com/problems/first-bad-version/
// Idea: We can binary search for the first item that is bad. If the item we
// query is bad, we know we need to search lower for the limit, and vice versa.
// Difficulty: medium
// Tags: binary-search

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    long long lo = 1, hi = n;
    while (hi > lo) {
      long long mid = (lo + hi) / 2;
      if (isBadVersion((int)mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
