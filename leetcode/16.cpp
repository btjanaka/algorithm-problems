// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 16
// Title: 3Sum Closest
// Link: https://leetcode.com/problems/3sum-closest
// Idea: See 3Sum (#15) for more info.
// Difficulty: medium
// Tags: implementation, arrays, sorting
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    // Same as 3 sum, but instead of keeping track of a list of solutions,
    // keep track of closest sum.

    int res = 0;
    int min_d = INT_MAX;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int curr_sum = nums[i] + nums[left] + nums[right];
        int curr_d = abs(curr_sum - target);
        if (curr_d < min_d) {
          res = curr_sum;
          min_d = curr_d;
        }

        // Move the sum closer
        if (curr_sum > target) {
          // Overshot, so decrease curr_sum
          --right;
        } else if (curr_sum < target) {
          // Undershot, increase curr_sum
          ++left;
        } else {
          // jackpot (exact match)
          return curr_sum;
        }
      }
    }
    return res;
  }
};
