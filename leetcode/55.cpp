// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 55
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return true;
    int end = n - 1;
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
      if (!dp[i]) continue;
      if (!dp[min(end, i + nums[i])]) {
        for (int j = i + 1; j <= i + nums[i] && j < n; ++j) {
          dp[j] = true;
          if (j == end) return true;
        }
      }
    }
    return false;
  }
};
