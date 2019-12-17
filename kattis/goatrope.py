# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) goatrope
# Title: Goat Rope
# Link: https://open.kattis.com/problems/goatrope
# Idea: If the goat is within the xy bounds of the rectangle, check its distance
# to a wall. Otherwise, check distance to a corner.
# Difficulty: easy
# Tags: geometry

import sys
from math import sqrt


def dist(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    return sqrt(dx * dx + dy * dy)


for line in sys.stdin:
    x, y, x1, y1, x2, y2 = map(float, line.split())
    d = None
    if (x <= x2 and x >= x1):
        d = min(abs(y - y1), abs(y - y2))
    elif (y <= y2 and y >= y1):
        d = min(abs(x - x1), abs(x - x2))
    else:
        d = min(dist(x, y, x1, y1), dist(x, y, x1, y2), dist(x, y, x2, y1),
                dist(x, y, x2, y2))
    print(d)
