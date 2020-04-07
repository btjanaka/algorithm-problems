// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 34
// Title: Find First and Last Position of Element in Sorted Array
// Link:
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
// Idea: Code Golf :) -- use binary search since the array is sorted.
// Difficulty: medium
// Tags: binary-search
struct Solution {
  vector<int> searchRange(vector<int>& n, int t) {
    auto b = n.begin(), e = n.end(), x = lower_bound(b, e, t);
    if (x == e || *x != t) return {-1, -1};
    return {x - b, upper_bound(b, e, t) - b - 1};
  }
};
