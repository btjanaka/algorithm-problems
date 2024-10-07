// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 3275
// Title: K-th Nearest Obstacle Queries
// Link: https://leetcode.com/problems/k-th-nearest-obstacle-queries/
// Idea: Maintain a priority queue with the closest k entries found so far.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    priority_queue<int> top_k;
    vector<int> res;
    for (const auto& q : queries) {
      int d = abs(q[0]) + abs(q[1]);
      if (top_k.size() < k) {
        top_k.push(d);
      } else if (d < top_k.top()) {
        top_k.push(d);
        top_k.pop();
      }

      if (top_k.size() < k) {
        res.push_back(-1);
      } else {
        res.push_back(top_k.top());
      }
    }
    return res;
  }
};
