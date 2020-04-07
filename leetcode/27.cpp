// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 27
// Title: Remove Element
// Link: https://leetcode.com/problems/remove-element
// Idea: Move all the values to the end of the array by swapping the item at
// the current index with the item at a "back pointer" at the end of the array.
// Difficulty: easy
// Tags: implementation
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int back_ptr = nums.size() - 1;
    for (int i = 0; i <= back_ptr; ++i) {
      while (back_ptr >= 0 && nums[i] == val) {
        if (i != back_ptr) {
          swap(nums[i], nums[back_ptr]);
          --back_ptr;
        } else {
          --back_ptr;
          break;
        }
      }
    }
    return back_ptr + 1;
  }
};
