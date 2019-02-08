// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 121
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
