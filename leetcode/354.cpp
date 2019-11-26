// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 354
// Title: Russian Doll Envelopes
// Link: https://leetcode.com/problems/russian-doll-envelopes/
// Idea: Use Longest Increasing Subsequence - I used the O(n^2) version but
// there's definitely faster ones (O(n log n))
// Difficulty: medium
// Tags: longest-increasing-subsequence, dynamic-programming
class Solution {
 public:
  // speedup :D
  Solution() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }

  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    if (n == 0) return 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      dp[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (envelopes[j][0] < envelopes[i][0] &&
            envelopes[j][1] < envelopes[i][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
