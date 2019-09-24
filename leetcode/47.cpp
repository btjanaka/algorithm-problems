// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 47
// Title: Permutations II
// Link: https://leetcode.com/problems/permutations-ii/submissions/
// Idea: It's just an application of the next permutation algorithm. That
// algorithm will automatically generate the unique permutations, since it is
// agnostic of the ordering. I suppose I could implement the next permutation
// algorithm, but...
// Difficulty: medium
// Tags: permutations
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    res.push_back(nums);
    while (next_permutation(nums.begin(), nums.end())) res.push_back(nums);
    return res;
  }
};
