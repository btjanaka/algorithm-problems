# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeForces) 1331d
# Title: Again?
# Link: https://codeforces.com/contest/1331/problem/D
# Idea: Check if the number is odd or even :p
# Difficulty: easy
# Tags: april-fools

import sys

for line in sys.stdin:
    print(int(line, base=16) % 2)
