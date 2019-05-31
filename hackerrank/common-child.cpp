// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) common-child
// Title: Common Child
// Link: https://www.hackerrank.com/challenges/common-child/
// Idea: Longest Common Subsequence
// Difficulty: easy
// Tags: string, LCS
#include <bits/stdc++.h>

using namespace std;

int commonChild(string s1, string s2) {
  int n = s1.size(), m = s2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << commonChild(s1, s2);
  return 0;
}
