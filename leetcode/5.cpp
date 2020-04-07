// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 5
// Title: Longest Palindromic Substring
// Link: https://leetcode.com/problems/longest-palindromic-substring
// Idea: See code comments.
// Difficulty: medium
// Tags: strings
class Solution {
 public:
  string longestPalindrome(string s) {
    // Choose each point in the string, and expand out sideways - but also check
    // right
    //   complexity: n for each character, n to expand, 2 for right check - 2n^2
    int max_len = 0;
    int left_start = 0;
    for (int i = 0; i < s.size(); ++i) {
      // Starting at middle
      int curr_len;
      int left;
      for (left = i;
           left >= 0 && (i - left + i) < s.size() && s[left] == s[i - left + i];
           --left)
        ;
      ++left;
      curr_len = 2 * (i - left) + 1;
      if (curr_len > max_len) {
        max_len = curr_len;
        left_start = left;
      }

      // Starting with current character and one to the right of it
      if (i < s.size() - 1 && s[i] == s[i + 1]) {
        for (left = i; left >= 0 && (i - left + i + 1) < s.size() &&
                       s[left] == s[i - left + i + 1];
             --left)
          ;
        ++left;
        curr_len = 2 * (i - left) + 2;
        if (curr_len > max_len) {
          max_len = curr_len;
          left_start = left;
        }
      }
    }
    return s.substr(left_start, max_len);
  }
};
