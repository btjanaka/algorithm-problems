// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 506
// Title: Relative Ranks
// Link: https://leetcode.com/problems/relative-ranks/
// Idea: Use a priority queue to sort everything and then pop it all out. Can
// also use a sorting algorithm.
// Difficulty: Easy
// Tags:
typedef pair<int, int> ii;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<ii, vector<ii>, less<ii>> pq;

    for (int i = 0; i < score.size(); ++i) {
      pq.push({score[i], i});
    }

    vector<string> results(score.size());

    for (int i = 0; i < score.size(); ++i) {
      auto x = pq.top();
      pq.pop();
      if (i == 0) {
        results[x.second] = "Gold Medal";
      } else if (i == 1) {
        results[x.second] = "Silver Medal";
      } else if (i == 2) {
        results[x.second] = "Bronze Medal";
      } else {
        results[x.second] = to_string(i + 1);
      }
    }
    return results;
  }
};
