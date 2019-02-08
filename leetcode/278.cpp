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
