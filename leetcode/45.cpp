// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 45
// Title: Jump Game II
// Link: https://leetcode.com/problems/jump-game-ii
// Idea: After the first jump, we will have a range of indices that we can
// reach. After the next jump, we will have another range of indices that we can
// reach, but we can avoid re-checking the indices that we reached after the
// first jump. Thus, after each jump, we can have a "min_reachable" and
// "max_reachable" index. Once max_reachable reaches or exceeds the last index,
// we terminate.
// Difficulty: medium
// Tags: breadth-first-search, arrays
class Solution {
 public:
  int jump(vector<int>& nums) {
    int min_reachable = 0;
    int max_reachable = 0;
    int jumps;
    for (jumps = 0; max_reachable < nums.size() - 1; ++jumps) {
      int next_max = max_reachable;
      for (int i = min_reachable; i <= max_reachable; ++i) {
        next_max = max(next_max, i + nums[i]);
      }
      min_reachable = max_reachable;
      max_reachable = next_max;
    }
    return jumps;
  }
};
