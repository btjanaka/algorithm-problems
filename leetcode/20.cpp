// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 20
class Solution {
 public:
  bool isValid(string s) {
    stack<char> parens;
    for (int i = 0; i < s.size(); ++i) {
      switch (s[i]) {
        // Push closing parens when seeing open parens
        case '(':
          parens.push(')');
          break;
        case '[':
          parens.push(']');
          break;
        case '{':
          parens.push('}');
          break;
        default:
          // closing parens
          if (parens.empty() || s[i] != parens.top()) {
            return false;
          }
          parens.pop();
      }
    }
    return parens.empty();
  }
};
