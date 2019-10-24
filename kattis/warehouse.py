# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) warehouse
# Title: Warehouse
# Link: https://open.kattis.com/problems/warehouse
# Idea: Counting with a dictionary
# Difficulty: easy
# Tags: implementation

import sys
from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    d = defaultdict(int)
    for k in range(n):
        toy, count = input().split()
        count = int(count)
        d[toy] += count
    print(len(d))
    for toy, count in sorted(d.items(), key=lambda x: (-x[1], x[0])):
        print(f"{toy} {count}")
