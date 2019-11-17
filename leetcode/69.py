# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 69
# Title: Sqrt(x)
# Link: https://leetcode.com/problems/sqrtx/
# Idea: Ummm...
# Difficulty: easy
# Tags: math
from math import sqrt, floor


class Solution:

    def mySqrt(self, x: int) -> int:
        return floor(sqrt(x))
