// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 46
// Title: Permutations
// Link: https://leetcode.com/problems/permutations
// Idea: Use recursive backtracking to generate all the permutations.
// Difficulty: medium
// Tags: recursion, backtracking
class Solution {
 public:
  void generate(vector<int>& tmp, int count, vector<int>& nums, long long used,
                vector<vector<int>>& res) {
    if (count == nums.size()) {
      res.push_back(tmp);
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (!(used & (1L << i))) {
        tmp[count] = nums[i];
        generate(tmp, count + 1, nums, used | (1L << i), res);
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> tmp(nums.size());
    generate(tmp, 0, nums, 0, res);
    return res;
  }
};
