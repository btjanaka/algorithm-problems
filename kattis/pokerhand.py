# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) pokerhand
# Title: Poker Hand
# Link: https://open.kattis.com/problems/pokerhand
# Idea: Just count the number of cards with each rank.
# Difficulty: easy
# Tags: math

import sys
from collections import *
for line in sys.stdin:
    c = line.split()
    h = [s[0] for s in c]
    n = defaultdict(int)
    for a in h:
        n[a] += 1
    print(max(n.values()))
