// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 39
// Title: Combination Sum
// Link: https://leetcode.com/problems/combination-sum/description/
// Idea: Top-down dynamic programming (top-down necessary due to having to
// return the list of solutions.
// Difficulty: Medium
// Tags: dp
void f(int target, int idx, vector<int>& cur, vector<int>& candidates, vector<vector<int>>& results) {
    if(target < 0) return;

    if(target == 0) {
        results.push_back(cur);
        return;
    }

    if(idx >= candidates.size()) return;

    // Use the current value.
    cur.push_back(candidates[idx]);
    f(target - candidates[idx], idx, cur, candidates, results);
    cur.pop_back();

    // Skip the current value.
    f(target, idx + 1, cur, candidates, results);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> cur;

        f(target, 0, cur, candidates, results);

        return results;
    }
};
