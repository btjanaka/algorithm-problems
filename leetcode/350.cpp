// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 350
// Title: Intersection of Two Arrays II
// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Idea: Use a multiset so that we know how many times each element appears :)
// It is also possible to use an unordered_map that maps from element to number
// of appearances of the element -- this may be faster since multiset is a bit
// slow.
// Difficulty: Easy
// Tags:
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> set1;
    for (const auto& x : nums1) {
      set1.insert(x);
    }
    vector<int> result;
    for (const auto& x : nums2) {
      auto loc = set1.find(x);
      if (loc != set1.end()) {
        set1.erase(loc);
        result.push_back(x);
      }
    }
    return result;
  }
};
