// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 11
class Solution {
 public:
  int maxArea(vector<int>& height) {
    // Move the two sides closer and closer together
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left != right) {
      max_area =
          max(max_area, (right - left) * min(height[left], height[right]));
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return max_area;
  }
};
