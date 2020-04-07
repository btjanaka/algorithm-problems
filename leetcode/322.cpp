// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 322
// Title: Coin Change
// Link: https://leetcode.com/problems/coin-change
// Idea: See code comments.
// Difficulty: medium
// Tags: dynamic-programming
class Solution {
 public:
  // Build a dp table where each index represents the minimum amount of coins to
  // get to that amount. Then return the coins at the amount index.
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= amount; ++i) {
      if (i == 0 || dp[i] > 0) {
        for (int j = 0; j < coins.size(); ++j) {
          int next_val = i + coins[j];
          if (next_val > 0 && next_val <= amount) {
            if (dp[next_val] == 0) {
              dp[next_val] = dp[i] + 1;
            } else {
              dp[next_val] = min(dp[i] + 1, dp[next_val]);
            }
          }
        }
      }
    }
    return dp[amount] == 0 ? -1 : dp[amount];
  }
};
