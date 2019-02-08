// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 28
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    if (haystack.size() < needle.size()) return -1;
    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
      bool match = true;
      for (int j = 0; j < needle.size(); ++j) {
        if (haystack[i + j] != needle[j]) {
          match = false;
          break;
        }
      }
      if (match) return i;
    }
    return -1;
  }
};
