// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 66
// Title: Plus One
// Link: https://leetcode.com/problems/plus-one
// Idea:
// Difficulty: easy
// Tags: implementation, math
class Solution {
  public int[] plusOne(int[] digits) {
    boolean extra = false;
    for (int i = digits.length - 1; i >= 0; --i) {
      if (digits[i] == 9) {
        digits[i] = 0;
        if (i == 0)
          extra = true;
      } else {
        ++digits[i];
        break;
      }
    }
    if (extra) {
      int[] res = new int[digits.length + 1];
      res[0] = 1;
      for (int i = 1; i < res.length; ++i) {
        res[i] = digits[i - 1];
      }
      return res;
    }
    return digits;
  }
}
