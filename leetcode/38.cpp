// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 38
class Solution {
 public:
  string generateSay(const string& cur) {
    string res;
    int i = 0;
    int count;
    while (i < cur.size()) {
      count = 1;
      ++i;  // Make sure that we move forward at least 1
      while (i < cur.size() && cur[i] == cur[i - 1]) {
        ++i;
        ++count;
      }
      res.push_back(count + '0');
      res.push_back(cur[i - 1]);
    }
    return res;
  }

  string countAndSay(int n) {
    if (n <= 0) return "";

    string res = "1";

    for (int i = 1; i < n; ++i) {
      res = generateSay(res);
    }

    return res;
  }
};
