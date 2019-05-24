# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeForces) 630g
# Title: Challenge Pennants
# Link: http://codeforces.com/problemset/problem/630/G
# Idea: Iterate through all partitions of 3 and 5 and see how many ways you can
# place each partition.
# Difficulty: Medium
# Tags: combinatorics, math

from math import factorial

n = int(input())


def partition(L, x):
    if x == 0:
        if len(L) > n: return 0
        return int(factorial(n) / (factorial(n - len(L)) * factorial(len(L))))

    tot = 0
    for i in range(1, x + 1):
        L.append(i)
        tot += partition(L, x - i)
        L.pop()
    return tot


print(partition([], 5) * partition([], 3))
