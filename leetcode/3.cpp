// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 3
// Title: Longest Substring Without Repeating Characters
// Link:
// https://leetcode.com/problems/longest-substring-without-repeating-characters
// Idea: Go through s once. Keep track of characters and their indices. Keep a
// starting index for the substring. If a repeated character is found, move this
// starting index to the index of that repeated character + 1 if the index is
// greater.
// Difficulty: medium
// Tags: arrays
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int seen[128];
    memset(seen, -1, sizeof(seen));
    int max_len = 0;
    int start = 0;
    int curr_len;
    for (int i = 0; i < s.size(); ++i) {
      if (seen[s[i]] >= 0) {
        start = start > seen[s[i]] ? start : seen[s[i]] + 1;
      }
      curr_len = i - start + 1;
      max_len = curr_len > max_len ? curr_len : max_len;
      seen[s[i]] = i;
    }
    return max_len;
  }
};
