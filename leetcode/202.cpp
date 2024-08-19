// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 202
// Title: Happy Number
// Link: https://leetcode.com/problems/happy-number/
// Idea: Repeatedly compute the sum of square of digits of the numbers. Check if
// the sum has been seen before using a set. There seems to be a way to do this
// that is more mathematical but this method works. Complexity for the sum
// computation is O(log n) (specifically log base 10). Unclear what the maximum
// number of loops is for the numbers, but set check is O(1), so final
// complexity is O(??? log n).
// Difficulty: Easy
// Tags:
class Solution {
 public:
  int squareDigits(int n) {
    int sum = 0;
    while (n > 0) {
      int x = n % 10;
      sum += x * x;
      n /= 10;
    }
    return sum;
  }

  bool isHappy(int n) {
    unordered_set<int> nums;
    nums.insert(n);
    while (true) {
      int sum = squareDigits(n);
      if (sum == 1) return true;
      if (nums.find(sum) != nums.end()) return false;
      nums.insert(sum);
      n = sum;
    }
  }
};
