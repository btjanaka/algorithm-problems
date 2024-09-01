// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 53
// Title: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Idea: Kadane's algorithm. One intuition behind Kadane's is that if you have a
// subsequence that has a negative sum, it should never be allowed to continue
// into the current sequence because it will just drag you down.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int ans = INT_MIN;  // Set to INT_MIN so that if all numbers are negative,
                        // we will collect the greatest negative number as the
                        // answer.
    for (const auto& x : nums) {
      sum += x;
      ans = max(sum, ans);
      if (sum < 0) sum = 0;
    }
    return ans;
  }
};
