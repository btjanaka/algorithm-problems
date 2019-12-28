// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 397
// Title: Integer Replacement
// Link: https://leetcode.com/problems/integer-replacement/
// Idea: Use a BFS starting from n and treating the children as {n/2} or {n-1,
// n+1} (depending on the parity of n). There's probably a more mathematical
// way, but this did beat 100% of C++ submissions.
// Difficulty: medium
// Tags: math, breadth-first-search
class Solution {
 public:
  int integerReplacement(int n) {
    queue<pair<long long, int>> q;
    unordered_set<int> s;
    q.push({n, 0});
    while (!q.empty()) {
      long long cur;
      int steps;
      tie(cur, steps) = q.front();
      if (cur == 1) return steps;
      q.pop();
      if (cur % 2 == 0) {
        if (s.find(cur / 2) == s.end()) {
          s.insert(cur / 2);
          q.push({cur / 2, steps + 1});
        }
      } else {
        if (s.find(cur + 1) == s.end()) {
          s.insert(cur + 1);
          q.push({cur + 1, steps + 1});
        }
        if (s.find(cur - 1) == s.end()) {
          s.insert(cur - 1);
          q.push({cur - 1, steps + 1});
        }
      }
    }
    return -1;
  }
};
