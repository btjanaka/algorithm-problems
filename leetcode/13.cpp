// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 13
class Solution {
 public:
  int romanToInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      switch (s[i]) {
        case 'I':
          ++res;
          break;
        case 'V':
          res += 5;
          if (i > 0 && s[i - 1] == 'I') {
            res -= 2;
          }
          break;
        case 'X':
          res += 10;
          if (i > 0 && s[i - 1] == 'I') {
            res -= 2;
          }
          break;
        case 'L':
          res += 50;
          if (i > 0 && s[i - 1] == 'X') {
            res -= 20;
          }
          break;
        case 'C':
          res += 100;
          if (i > 0 && s[i - 1] == 'X') {
            res -= 20;
          }
          break;
        case 'D':
          res += 500;
          if (i > 0 && s[i - 1] == 'C') {
            res -= 200;
          }
          break;
        case 'M':
          res += 1000;
          if (i > 0 && s[i - 1] == 'C') {
            res -= 200;
          }
          break;
      }
    }
    return res;
  }
};
