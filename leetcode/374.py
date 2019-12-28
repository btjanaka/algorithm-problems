# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 374
# Title: Guess Number Higher or Lower
# Link: https://leetcode.com/problems/guess-number-higher-or-lower/
# Idea: Binary search for the answer.
# Difficulty: easy
# Tags: binary-search

# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:


class Solution:

    def guessNumber(self, n: int) -> int:
        lo = 1
        hi = n
        while True:
            mid = (lo + hi) // 2
            res = guess(mid)
            if res == -1:
                hi = mid
            elif res == 1:
                lo = mid + 1
            else:
                return mid
