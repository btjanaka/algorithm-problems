// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 1497
// Title: Check If Array Pairs Are Divisible by k
// Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
// Idea: Mod each number by k and count the frequencies of the modulos.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> mods;
    for (int x : arr) {
      int m = x % k;
      if (m < 0) m += k;
      if (mods.find(m) == mods.end()) mods[m] = 0;
      ++mods[m];
    }

    bool match = true;
    for (auto p : mods) {
      int m = p.first, count = p.second;
      if (m == 0) {
        match = count % 2 == 0;
      } else {
        int complement = k - m;
        if (mods.find(complement) == mods.end() || mods[complement] != count) {
          match = false;
          break;
        }
      }
    }

    return match;
  }
};
