// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 14
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) return "";
    string prefix = "";
    for (int i = 0; true; ++i) {
      char match = strs[0][i];
      bool all_matched = true;
      for (int j = 0; j < strs.size(); ++j) {
        if (i >= strs[j].size()) return prefix;
        all_matched &= strs[j][i] == match;
      }
      if (all_matched) {
        prefix += match;
      } else {
        return prefix;
      }
    }
  }
};
