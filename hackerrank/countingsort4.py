# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) countingsort4
# Title: The Full Counting Sort
# Link: https://www.hackerrank.com/challenges/countingsort4/problem
# Idea: Implement what they say. Make sure to build the string before printing
# it out, as printing takes a while otherwise.
# Difficulty: medium
# Tags: implementation, counting-sort, sorting
from math import ceil

res = [[] for _ in range(100)]
n = int(input())
for i in range(1, n + 1):
    x, s = input().strip().split()
    res[int(x)].append('-' if i <= ceil(n / 2) else s)

print(' '.join(' '.join(l) for l in filter(lambda x: len(x) > 0, res)))
