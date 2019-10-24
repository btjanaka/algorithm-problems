# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) turningtrominos
# Title: Turning Trominos
# Link: https://open.kattis.com/problems/turningtrominos
# Idea: Start with a big tromino, then keep finding what smaller part of the
# tromino we are in, until we are at the basic tromino. Translate the part we
# find along the way so that it is touching the x and y axis.
# Difficulty:
# Tags:

import sys
from collections import defaultdict

n = int(input())
for _ in range(n):
    x, y = map(int, input().split())
    h = 2**61
    rotation = 0
    while h != 2:
        """
        Sections

        |---h---|
         0 0
         0 1
         2 1 1 3
         2 2 3 3
        """
        section = None
        if (y >= h // 2 and x < h // 4) or (x >= h // 4 and y >= 3 * h // 4):
            # In section 0, we add a rotation count, translate the point down,
            # and rotate it so it looks like it came from section 2.
            section = 0

            rotation += 1
            if rotation == 4: rotation = 0

            y -= h // 2
            y, x = x, h // 2 - y - 1
        elif y >= h // 4 and y < 3 * h // 4 and x >= h // 4 and x < 3 * h // 4:
            # In section 1, we just translate diagonally.
            section = 1
            x -= h // 4
            y -= h // 4
        elif (y < h // 2 and x < h // 4) or (y < h // 4 and x < h // 2):
            # Nothing happens in section 2
            section = 2
        else:
            # In section 3, we subtract a rotation count, translate the point
            # left, and rotate it.
            section = 3

            rotation -= 1
            if rotation == -1: rotation = 3

            x -= h // 2
            y, x = h // 2 - x - 1, y
        h //= 2
    print(rotation)
