// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 18
// Title: 4Sum
// Link: https://leetcode.com/problems/4sum
// Idea: See 3Sum ($#15) - this solution is very similar to the 3 sum solution,
// except that is uses two outside loops instead of one because we need
// quadruplets instead of triplets.
// Difficulty: medium
// Tags: implementation, arrays, sorting
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    cout << n << endl;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        for (int j = i + 1; j < n - 2; ++j) {
          if (j == i + 1 || nums[j] != nums[j - 1]) {
            int left = j + 1;
            int right = n - 1;
            while (left < right) {
              int curr = nums[i] + nums[j] + nums[left] + nums[right];
              if (curr == target) {
                res.push_back({nums[i], nums[j], nums[left], nums[right]});
                ++left;
                while (nums[left] == nums[left - 1]) ++left;
                --right;
                while (nums[right] == nums[right + 1]) --right;
              } else if (curr < target) {
                ++left;
              } else {
                --right;
              }
            }
          }
        }
      }
    }
    return res;
  }
};
