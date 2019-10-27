# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 58
# Title: Length of Last Word
# Link: https://leetcode.com/problems/length-of-last-word/
# Idea: Split the string and return length of the last word.
# Difficulty: easy
# Tags: string
class Solution:

    def lengthOfLastWord(self, s: str) -> int:
        tokens = s.split()
        return 0 if len(tokens) == 0 else len(tokens[-1])
