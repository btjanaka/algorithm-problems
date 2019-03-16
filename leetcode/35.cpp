// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 35
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;
    if (target < nums[0]) return 0;
    if (target > nums.back()) return nums.size();

    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
