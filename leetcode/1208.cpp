// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 1208
// Title: Get Equal Substrings Within Budget
// Link: https://leetcode.com/problems/get-equal-substrings-within-budget/
// Idea: This is a variation of the 1D DP range sum problem. We iterate through
// the string once, and as we do so, we keep trying to extend the changes until
// we cannot afford them anymore. We keep track of a list of changes, so when we
// can no longer afford changes, we pop off the earliest changes until we can.
// Then we continue on.
// Difficulty: medium
// Tags: dp, dynamic-programming
class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    deque<int> prices;
    int n = s.size();
    int cur_tot = 0;
    int cur_len = 0;
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
      int cost = abs(s[i] - t[i]);
      while (!prices.empty() && cur_tot + cost > maxCost) {
        cur_tot -= prices.front();
        prices.pop_front();
        --cur_len;
      }
      if (cost + cur_tot <= maxCost) {
        prices.push_back(cost);
        cur_tot += cost;
        ++cur_len;
        max_len = max(cur_len, max_len);
      }
    }
    return max_len;
  }
};
