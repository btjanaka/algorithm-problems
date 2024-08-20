// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 349
// Title: Intersection of Two Arrays
// Link: https://leetcode.com/problems/intersection-of-two-arrays/
// Idea: Use a set to keep track of the intersection. There are probably faster
// ways that take advantage of how the input is relatively small (only up to
// 1000 for each value).
// Difficulty: Easy
// Tags:
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    for (const auto& x : nums1) {
      set1.insert(x);
    }
    unordered_set<int> intersect;
    vector<int> result;
    for (const auto& x : nums2) {
      if (set1.find(x) != set1.end() && intersect.find(x) == intersect.end()) {
        intersect.insert(x);
        result.push_back(x);
      }
    }
    return result;
  }
};
