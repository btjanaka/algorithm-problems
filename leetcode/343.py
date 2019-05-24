# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 343
# Title: Integer Break
# Link: https://leetcode.com/problems/integer-break/
# Idea: Keep breaking down the number as much as we can, but pay attention to
# step size.
# Difficulty: medium
# Tags: math
from functools import reduce
from operator import mul


def calc(L, n):
    if n == 0: return -1 if len(L) <= 1 else reduce(mul, L)

    mx = 0
    lo = L[-1] if len(L) > 0 else (1 if n == 2 else 2)
    for i in range(lo, n + 1):
        L.append(i)
        mx = max(mx, calc(L, n - i))
        L.pop()
    return mx


class Solution:

    def integerBreak(self, n: int) -> int:
        if n == 2: return 1
        if n == 3: return 2
        return calc([], n)
