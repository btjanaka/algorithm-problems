// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 1
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
    // Technically not necessary, since problem specifies there will be a
    // solution
    return {-1, -1};
  }
};
