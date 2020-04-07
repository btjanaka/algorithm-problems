// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 22
// Title: Generate Parentheses
// Link: https://leetcode.com/problems/generate-parentheses
// Idea: Use recursive backtracking to generate every combo possible while
// adding in several checks to make sure everything is valid.
// Difficulty: medium
// Tags: recursion, backtracking
class Solution {
 public:
  void generate(int left, int right, int tot, int n, char cur[],
                vector<string>& res) {
    // End case: enough parens
    if (tot == 2 * n) {
      res.push_back(cur);
      return;
    }

    // Only put up to n left parens
    if (left < n) {
      cur[tot] = '(';
      generate(left + 1, right, tot + 1, n, cur, res);
    }

    // Never let the number of right parens exceed the number of left
    if (right < left) {
      cur[tot] = ')';
      generate(left, right + 1, tot + 1, n, cur, res);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n == 0) return res;
    char cur[(2 * n) + 1];
    memset(cur, 0, sizeof(cur));
    generate(0, 0, 0, n, cur, res);
    return res;
  }
};
