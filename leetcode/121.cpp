// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 121
// Title: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Idea: As you iterate through the array, keep track of the current minimum
// stock price, and the current maximum profit.
// Difficulty: easy
// Tags: arrays
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int mx = 0;
    int cur_min = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
      mx = max(mx, prices[i] - cur_min);
      cur_min = min(cur_min, prices[i]);
    }
    return mx;
  }
};
