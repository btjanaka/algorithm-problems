// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 3043
// Title: Find the Length of the Longest Common Prefix
// Link:
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
// Idea: Put all the prefixes from arr1 into a set and then check if the
// prefixes exist in the set when running through arr2.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<string> prefixes1;
    for (const int x : arr1) {
      string s = to_string(x);
      string p;
      for (int i = 0; i < s.size(); ++i) {
        p.push_back(s[i]);
        prefixes1.insert(p);
      }
    }

    int longestPrefix = 0;
    for (const int x : arr2) {
      string s = to_string(x);
      string p;
      for (int i = 0; i < s.size(); ++i) {
        p.push_back(s[i]);
        if (prefixes1.find(p) != prefixes1.end()) {
          longestPrefix = max(longestPrefix, i + 1);
        }
      }
    }

    return longestPrefix;
  }
};
