// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 26
// Title: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array
// Idea: Since the array is sorted, duplicates are very easy to detect -- they
// will be right next to each other.
// Difficulty: easy
// Tags: implementation, arrays
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    vector<int> copy = std::move(nums);
    nums.clear();
    for (int i = 0; i < copy.size(); ++i) {
      if (i == 0 || copy[i] != copy[i - 1]) {
        nums.push_back(copy[i]);
      }
    }
    return nums.size();
  }
};
