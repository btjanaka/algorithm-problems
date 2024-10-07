# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 2696
# Title: Minimum String Length After Removing Substrings
# Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
# Idea: Just keep removing AB and CD.
# Difficulty: Easy
# Tags:
class Solution:

    def minLength(self, s: str) -> int:
        prev_len = len(s)
        while True:
            s = s.replace("AB", "")
            s = s.replace("CD", "")
            if len(s) == prev_len:
                break
            prev_len = len(s)
        return len(s)
