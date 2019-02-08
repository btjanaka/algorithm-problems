// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 17
class Solution {
 public:
  // '2', '3', ... '9'
  string letters[8] = {"abc", "def",  "ghi", "jkl",
                       "mno", "pqrs", "tuv", "wxyz"};

  // Generate the strings recursively
  void generate(int place, char cur[], const string& digits,
                vector<string>& res) {
    // End case: the string is long enough
    if (place == digits.size()) {
      res.push_back(cur);
      return;
    }
    const string& cur_letters = letters[digits[place] - '2'];
    for (int i = 0; i < cur_letters.size(); ++i) {
      cur[place] = cur_letters[i];
      generate(place + 1, cur, digits, res);
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    char cur[digits.size() + 1];
    memset(cur, 0, sizeof(cur));
    generate(0, cur, digits, res);
    return res;
  }
};
