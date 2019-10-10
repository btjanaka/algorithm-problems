# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) company-logo
# Title: Company Logo
# Link: https://www.hackerrank.com/challenges/most-commons/problem
# Idea: Count the letters and output the most common.
# Difficulty: easy
# Tags: map, dict
from collections import defaultdict
counts = defaultdict(int)
for ch in input().strip():
    counts[ch] += 1
for ch, n in sorted(counts.items(), key=lambda x: (-x[1], x[0]))[:3]:
    print(ch, n)
