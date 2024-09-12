// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 1684
// Title: Count the Number of Consistent Strings
// Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Idea: Implementation; just check characters.
// Difficulty: easy
// Tags:
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    vector<bool> ok(26, false);
    for (int i = 0; i < allowed.size(); ++i) ok[allowed[i] - 'a'] = true;

    int consistent = 0;
    for (const auto& w : words) {
      bool all = true;
      for (const char c : w) {
        if (!ok[c - 'a']) {
          all = false;
          break;
        }
      }
      if (all) ++consistent;
    }

    return consistent;
  }
};
