// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 6
// Title: ZigZag Conversion
// Link: https://leetcode.com/problems/zigzag-conversion/
// Idea: See code comments.
// Difficulty: medium
// Tags: implementation
class Solution {
 public:
  string convert(string s, int n) {
    // Take d = 2 * n - 2   (n is number of rows)
    // There is a pattern where if you number the letters, the rows will
    // contain:
    // 0: 0, d, 2*d, 3*d, ...
    // 1: 1, 1 + d - 2, 1 + d, 1 + 2 * d - 2, 1 + 2 * d, ...
    // 2: 2, 2 + d - 4, 2 + d, 2 + 2 * d - 4, 2 + 2 * d, ...
    // ...
    // n-1: n-1, n-1 + d, n-1 + 2 * d, ...
    int d = max(1, 2 * n - 2);  // Has to be one when n = 1
    string res(s.size(), 0);
    int res_i = 0;
    for (int i = 0; i < n; ++i) {
      int j = i;
      bool alt = true;
      while (j < s.size()) {
        res[res_i++] = s[j];
        // Special case to avoid repetition for first and last rows
        if (i == 0 || i == n - 1) {
          j += d;
          continue;
        }

        // Otherwise, increment j by the appropriate amount
        if (alt) {
          j += d - 2 * i;
        } else {
          j += 2 * i;
        }
        alt = !alt;
      }
    }
    return res;
  }
};
