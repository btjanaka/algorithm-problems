// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 9
// Title: Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number/
// Idea: See code comments.
// Difficulty: easy
// Tags: math, implementation
class Solution {
 public:
  bool isPalindrome(int x) {
    // Move digits from the left number to the right
    // number and check if the numbers are ever equal
    // Two separate cases for when the palindrome is
    // odd and even length.
    // Better solution: simply reverse the number and
    // check if reversed is same as initial.

    // 0 works
    if (!x) return true;

    // Negatives and multiples of 10 fail
    if (x < 0 || x % 10 == 0) return false;

    int left, right;

    // Check palindromes of even length
    left = x;
    right = 0;
    while (left > 0) {
      right *= 10;
      right += left % 10;
      left /= 10;
      if (left == right) return true;
    }

    // Check palindromes of odd length - one digit is
    // always shared between left and right during the
    // comparison
    left = x;
    right = 0;
    while (left > 0) {
      right *= 10;
      right += left % 10;
      if (left == right) return true;
      left /= 10;
    }

    return false;
  }
};
