// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 96
class Solution {
 public:
  // count(n) = sum[i = 1 to n] count(i - 1) * count(n - i)
  // Intuitively, think of this as you split the tree at a certain vertex i
  // and then multiply the number of ways to make the left side of the tree by
  // the number of ways to make the right side. You always know all the elements
  // on the left are less than i and the elements on the right are greater than
  // i since this is a BST.
  //         i
  //     /       \
  // [1, i)    (i, n]
  int count(int n, vector<int>& dp) {
    if (dp[n] != -1) return dp[n];
    dp[n] = 0;
    for (int i = 1; i <= n; ++i) dp[n] += count(i - 1, dp) * count(n - i, dp);
    return dp[n];
  }

  int numTrees(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = dp[1] = 1;  // base cases
    return count(n, dp);
  }
};
