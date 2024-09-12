// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 264
// Title: Ugly Number II
// Link: https://leetcode.com/problems/ugly-number-ii/
// Idea: Make a heap that stores the current numbers. Pop the top one and insert
// it again multiplied by 2, 3, and 5. Repeat until you have removed the nth
// number.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int nthUglyNumber(int n) {
    set<long long> s;
    s.insert(1);
    long long cur;
    for (int i = 1; i <= n; ++i) {
      cur = *(s.begin());
      s.erase(s.begin());
      s.insert(cur * 2);
      s.insert(cur * 3);
      s.insert(cur * 5);
    }
    return cur;
  }
};
