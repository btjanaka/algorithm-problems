// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 30
// Title: Substring with Concatenation of All Words
// Link:
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Idea: Brute force, could be better somehow.
// Difficulty: medium
// Tags: strings
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.size() == 0) return {};
    if (words.size() == 0) return {};

    int word_len = words[0].size();
    int total_len = word_len * words.size();
    int s_len = s.size();

    vector<int> locations;

    multiset<string> word_set(words.begin(), words.end());
    multiset<string> cur;

    for (int i = 0; i < s_len - total_len + 1; ++i) {
      bool ok = true;
      for (int j = 0; j < total_len; j += word_len) {
        string sub = s.substr(i + j, word_len);
        if (word_set.find(sub) == word_set.end()) {
          ok = false;
          break;
        }
        cur.insert(sub);
      }
      if (ok && cur == word_set) {
        locations.push_back(i);
      }
      cur.clear();
    }

    return locations;
  }
};
