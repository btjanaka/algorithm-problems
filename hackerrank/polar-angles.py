# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) polar-angles
# Title: Polar Angles
# Link: https://www.hackerrank.com/challenges/polar-angles/problem
# Idea: Use atan2 to get the polar angle.
# Difficulty: easy
# Tags: geometry

from math import atan2, pi, sqrt

[
    print(p[0], p[1]) for p in sorted(
        [list(map(int,
                  input().split())) for _ in range(int(input()))],
        key=lambda p: (atan2(p[1], p[0]) % (2 * pi), sqrt(p[0]**2 + p[1]**2)),
    )
]  # haha
