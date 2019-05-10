// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 44
class Solution {
 public:
  bool isMatch(string input, string regex) {
    int n = input.size(), m = regex.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // initial states
    dp[0][0] = true;
    for (int r = 1; r <= m && regex[r - 1] == '*'; ++r) {
      dp[0][r] = true;
    }

    for (int i = 0; i < n; ++i) {
      for (int r = 0; r <= m; ++r) {
        if (dp[i][r]) {
          if (r > 0 && regex[r - 1] == '*') {
            dp[i + 1][r] = true;
          }
          if (r < m &&
              (regex[r] == '?' || regex[r] == '*' || regex[r] == input[i])) {
            dp[i + 1][r + 1] = true;
            // epsilon closure
            for (int r2 = r + 2; r2 <= m && regex[r2 - 1] == '*'; ++r2) {
              dp[i + 1][r2] = true;
            }
          }
        }
      }
    }

    /*
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            printf("%d%c", dp[i][j] ? 1 : 0, j == m ? '\n' : ' ');
        }
    }
    */

    return dp[n][m];
  }
};
