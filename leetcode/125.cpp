// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 125
// Title: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/
// Idea: Check if letters on left and right are equal, ignoring non-alphanumeric
// characters.
// Difficulty: easy
// Tags: string, implementation
class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (!isalnum(s[left]))
        ++left;
      else if (!isalnum(s[right]))
        --right;
      else {
        if (tolower(s[left]) != tolower(s[right])) return false;
        ++left;
        --right;
      }
    }
    return true;
  }
};
