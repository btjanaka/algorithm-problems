// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 55
// Title: Jump Game
// Link: https://leetcode.com/problems/jump-game/
// Idea: Keep extending the maximum reach of our jumps as we iterate through the
// array. If we reach the max_reach and are unable to go any further, we have
// failed.
// Difficulty: medium
// Tags: arrays, ad-hoc
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int max_reach = 0;
    int i = 0;
    while (i < n - 1) {
      max_reach = max(max_reach, i + nums[i]);
      if (i < max_reach)
        ++i;
      else
        return false;
    }
    return true;
  }
};
