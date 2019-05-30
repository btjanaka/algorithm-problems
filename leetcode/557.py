# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 557
# Title: Reverse Words in a String III
# Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
# Idea: Split by white space, reverse, words, and join them back
# Difficulty: easy
# Tags: implementation, one-liner


class Solution:

    def reverseWords(self, s: str) -> str:
        return ' '.join(x[::-1] for x in s.split())
