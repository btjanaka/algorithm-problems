# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) heirsdilemma
# Title: Heir's Dilemma
# Link: https://open.kattis.com/problems/heirsdilemma
# Idea: Brute force the combos.
# Difficulty: easy
# Tags: math, complete-search, brute-force

import sys
for line in sys.stdin:
    a, b = map(int, line.split())
    tot = 0
    for c in range(a, b + 1):
        d = str(c)
        if len(set(d)) != 6:
            continue
        ok = True
        for ch in d:
            if ch == '0':
                ok = False
                break
            if c % int(ch) != 0:
                ok = False
                break
        if ok: tot += 1
    print(tot)
