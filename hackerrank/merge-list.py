# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) merge-list
# Title: Merge List
# Link: https://www.hackerrank.com/challenges/merge-list/problem
# Idea: We can see this as a problem of choosing N locations in a list of N+M
# items, with no regard to the ordering (since the order of the items in the
# length-N list is always the same). Thus, the solution is N+M choose N.
# Difficulty: medium
# Tags: math, combinatorics
from math import factorial

for _ in range(int(input())):
    n, m = map(int, input().split())
    # Minimize calculations by setting N to be the larger number
    n, m = max(n, m), min(n, m)
    res = 1
    for i in range(m):
        # Input is small enough to multiply without mod. Multiplying without
        # mod is preferred because dividing with mod (below) is complicated.
        res *= n + i + 1
    res //= factorial(m)
    print(res % (int(1e9) + 7))
