// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 49
// Title: Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/
// Idea: Make a map that goes from the sorted characters of each word to the
// list of words that have those characters. For example, "tan" is sorted as
// "ant" and so the map contains {"ant": ["tan", "nat"]}.
// Difficulty: Easy
// Tags:
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;

    for (const auto& s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      if (anagrams.find(key) == anagrams.end()) {
        anagrams[key] = vector<string>();
      }
      anagrams[key].push_back(s);
    }

    vector<vector<string>> output;
    for (const auto& x : anagrams) output.push_back(x.second);
    return output;
  }
};
