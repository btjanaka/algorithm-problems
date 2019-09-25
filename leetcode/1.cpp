// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 1
// Title: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Idea: The easy solution is to check every pair of elements, but this is
// O(n^2). To achieve O(n), the idea is to use a hash set that keeps track of
// which elements we have seen so far while iterating through the list. Then,
// for the value x, we can check if we have target - x in the set. In this
// solution, we specifically use a hash map instead of a set because we need to
// store the indices.
// Difficulty: easy
// Tags: set
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numtoindex;
    for (int i = 0; i < nums.size(); ++i) {
      int curr = nums[i];
      if (numtoindex.find(curr) != numtoindex.end()) {
        return {numtoindex[curr], i};
      }
      numtoindex[target - curr] = i;
    }
    // Technically not necessary, as the problem specifies we will always have
    // exactly one solution.
    return {-1, -1};
  }
};
