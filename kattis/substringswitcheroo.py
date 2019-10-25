# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) substringswitcheroo
# Title: Substring Switcheroo
# Link: https://open.kattis.com/problems/substringswitcheroo
# Idea: Brute force - but we store tuples that have the counts of each character
# (a-z)
# Difficulty: hard
# Tags: brute-force, complete-search

import sys
from collections import defaultdict

n = int(input())
for _ in range(n):
    a = input().strip()
    b = input().strip()
    n = len(a)

    # Store all substrings in b
    b_combos = set()
    for i in range(n):
        # Index i tells the number of occurrences of the ith character ('a' + i)
        counts = [0 for x in range(26)]
        for j in range(i, n):
            ch = b[j]
            counts[ord(ch) - 97] += 1
            b_combos.add(tuple(counts))

    # Search through all substrings in a
    res_i, res_j = 0, -1
    for i in range(n):
        counts = [0 for x in range(26)]
        for j in range(i, n):
            ch = a[j]
            counts[ord(ch) - 97] += 1
            if j - i + 1 > res_j - res_i + 1 and tuple(counts) in b_combos:
                res_i, res_j = i, j

    print("NONE" if res_j - res_i + 1 == 0 else a[res_i:res_j + 1])
