// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 198
// Title: House Robber
// Link: https://leetcode.com/problems/house-robber
// Idea:
// Difficulty: easy
// Tags: dynamic-programming
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = nums[i];
      if (i == 2)
        dp[i] += dp[i - 2];
      else if (i > 2)
        dp[i] += max(dp[i - 2], dp[i - 3]);
    }
    return max(dp[n - 1], dp[n - 2]);
  }
};
