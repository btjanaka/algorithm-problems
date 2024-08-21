// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 201
// Title: Bitwise AND of Numbers Range
// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Idea: See explanation in code.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    int res = 0;

    // All bits that will show up in the result must be in left because we are
    // performing AND on the entire range. Thus, we iterate over the bits in
    // left and check if they will still be on by the end of the range.
    //
    // For example, for 11 (base 2: 1011), only the bits in positions 0, 1, and
    // 3 can be on in the final result.
    for (int i = 0; left > 0; ++i) {
      // Check if the bit in position i is "on".
      if (left & 1) {
        // Compute the smallest number that is greater than left and has a 0
        // at position i.
        //
        // For example, for 11 (1011) at position i = 1, we would have (in base
        // 2) a = 10 and strippedLeft = 1010 in this calculation. The sum of
        // these is 1100 -- this is the smallest number that is greater than
        // 1011 and has a 0 in position 1. At position i = 3, we would have
        // a = 1000 and strippedLeft = 1000, with a sum of 10000 (again,
        // smallest number that is greater than 1011 and has a 0 in position 3).
        int a = 1 << i;
        int strippedLeft = left << i;

        // If the sum of a and strippedLeft is greater than the right range, we
        // are safe because we will never encounter a number with a 0 at
        // position i. Thus, we set the result bit. Note that this was
        // originally strippedLeft + a > right, but that causes overflow if
        // strippedLeft + a is more than int_max, so I rearranged the
        // inequality.
        if (strippedLeft > (right - a)) {
          res = res | (1 << i);
        }
      }

      left >>= 1;
    }

    return res;
  }
};
