// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 20
// Title: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses
// Idea: Use a stack to keep track of the current parentheses that you have seen
// while iterating through the array. If the next paren is opening, you push its
// corresponding closing paren on. If it is closing, it should match the top of
// the stack; otherwise, there is an error.
// Difficulty: easy
// Tags: stack
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
