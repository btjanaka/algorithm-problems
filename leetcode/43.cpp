// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 43
// Title: Multiply Strings
// Link: https://leetcode.com/problems/multiply-strings/
// Idea: Implement elementary school multiplication.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  string multiply(string s1, string s2) {
    vector<int> n1, n2;
    for (int i = 0; i < s1.size(); ++i)
      n1.push_back(s1[s1.size() - i - 1] - '0');
    for (int i = 0; i < s2.size(); ++i)
      n2.push_back(s2[s2.size() - i - 1] - '0');

    vector<vector<int>> rows(n1.size());
    for (int i = 0; i < n1.size(); ++i) {
      // Add zeros to the row.
      for (int j = 0; j < i; ++j) rows[i].push_back(0);

      // Multiply digit n1[i] by n2.
      int carry = 0;
      for (int j = 0; j < n2.size(); ++j) {
        int cur = n1[i] * n2[j] + carry;
        rows[i].push_back(cur % 10);
        carry = cur / 10;
      }
      if (carry != 0) rows[i].push_back(carry);
    }

    // Debug by printing the rows.
    // for(int i = 0; i < rows.size(); ++i) {
    //     cout << i << ":";
    //     for(int j = 0; j < rows[i].size(); ++j) {
    //         cout << " " << rows[i][j];
    //     }
    //     cout << endl;
    // }

    vector<int> ans;
    int carry = 0;
    for (int col = 0; true; ++col) {
      // Collect all digits in the row.
      int sum = carry;
      bool summing = false;  // Whether we are still summing digits.
      for (int i = 0; i < rows.size(); ++i) {
        if (col < rows[i].size()) {
          summing = true;
          sum += rows[i][col];
        }
      }

      if (!summing) break;

      ans.push_back(sum % 10);
      carry = sum / 10;
    }
    if (carry != 0) ans.push_back(carry);

    // Trim leading zeros.
    while (ans.size() > 1 && ans[ans.size() - 1] == 0) ans.pop_back();

    string ret;
    for (int i = ans.size() - 1; i >= 0; --i) ret.push_back(ans[i] + '0');

    return ret;
  }
};
