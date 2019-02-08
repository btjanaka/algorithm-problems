// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 45

// This solution kinda sucks... It's like the below solution but adds
// inefficiency because at each node it goes through the reachable nodes
// unnecessarily. Should be an O(n) solution but it is instead O(2n).
// https://leetcode.com/problems/jump-game-ii/discuss/18028/O(n)-BFS-solution
class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    int last = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = max(i + 1, last); j <= i + nums[i] && j < n; ++j) {
        dp[j] = dp[i] + 1;
        ++last;
      }
    }
    return dp[n - 1];
  }
};
