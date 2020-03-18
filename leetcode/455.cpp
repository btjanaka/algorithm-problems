// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 455
// Title: Assign Cookies
// Link: https://leetcode.com/problems/assign-cookies/
// Idea: Sort the children and the cookies. Iterate through the children; at
// each child, throw away cookies until we find one that can satisfy them. This
// works because smaller cookies cannot satisfy the next child, since the
// children are sorted in order of greed. By this same logic, we stop iterating
// through the children if we are unable to find cookies for any child.
// Difficulty: easy
// Tags: greedy
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int si = 0;
    int tot = 0;

    // Iterate through the children.
    for (int gi = 0; gi < g.size() && si < s.size(); ++gi) {
      bool satisfied = false;
      // At each child, try to find a cookie that is good enough for them.
      while (si < s.size()) {
        if (s[si] >= g[gi]) {
          // Found a cookie, so break the loop.
          satisfied = true;
          ++si;
          break;
        }
        ++si;
      }
      tot += satisfied;
      if (!satisfied) break;
    }
    return tot;
  }
};
