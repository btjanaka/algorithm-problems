// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 292
// Title: Nim Game
// Link: https://leetcode.com/problems/nim-game/
// Idea: You can make a slow solution with dp, but try looking at the pattern of
// who wins as n increases.
// Difficulty: easy
// Tags: math
struct Solution {
  bool canWinNim(int n) { return n % 4; }
};
