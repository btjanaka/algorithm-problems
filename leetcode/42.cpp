// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 42
class Solution {
 public:
  int trap(vector<int>& height) {
    // Count how much can be held going from left to right - keep track of a max
    // to the left. Count how much can be held going from right to left - keep
    // track of a max to the right. Take the min of the left and right.
    int mx;
    int len = height.size();
    if (len == 0) return 0;
    int trapped[len][2];  // 0 is left to right, 1 is right to left

    // left to right
    mx = height[0];
    for (int i = 0; i < len; ++i) {
      trapped[i][0] = max(mx - height[i], 0);
      mx = max(mx, height[i]);
    }

    // right to left
    mx = height[len - 1];
    for (int i = len - 1; i >= 0; --i) {
      trapped[i][1] = max(mx - height[i], 0);
      mx = max(mx, height[i]);
    }

    // Add up result - max of left and right
    int res = 0;
    for (int i = 0; i < len; ++i) res += min(trapped[i][0], trapped[i][1]);
    return res;
  }
};
