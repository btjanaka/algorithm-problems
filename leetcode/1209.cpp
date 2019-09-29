// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 1209
// Title: Remove All Adjacent Duplicates in String II
// Link:
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Idea: We maintain a result string that we push characters onto. We also
// maintain a "dup" list telling, for each character, how many times the
// character has been repeated up to that point. For instance, if we had the
// string "abcddd", the last character has a dup of 3. As we push characters
// onto the string, we check these dup values, and if the value matches k, we
// pop k characters from the string. This is O(n) because we push and pop at
// most 2n times.
// Difficulty: medium
// Tags: dp, dynamic-programming
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    string res;
    vector<int> dup;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      char ch = s[i];
      if (i == 0) {
        res.push_back(ch);
        dup.push_back(1);
      } else if (ch == res.back()) {
        if (dup.back() == k - 1) {
          for (int i = 1; i < k; ++i) {
            res.pop_back();
            dup.pop_back();
          }
        } else {
          res.push_back(ch);
          dup.push_back(dup.back() + 1);
        }
      } else {
        res.push_back(ch);
        dup.push_back(1);
      }
    }
    return res;
  }
};
