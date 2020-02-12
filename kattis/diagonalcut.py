# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) diagonalcut
# Title: Diagonal Cut
# Link: https://open.kattis.com/problems/diagonalcut
# Idea: A line only bisects a rectangle if it passes through the center of the
# rectangle. The line only passes through the center of a block if the lengths
# of the sides of the block are both odd. Thus, we need to find the smallest
# repeatable block in the main rectangle; this can be done by finding the GCD
# and dividing both sides by this GCD.
# Difficulty: medium
# Tags: computational-geometry

import sys


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


for line in sys.stdin:
    a, b = map(int, line.split())
    g = gcd(max(a, b), min(a, b))

    # New side lengths.
    a2, b2 = a // g, b // g

    # If any side length is even, answer is 0.
    if a2 % 2 == 0 or b2 % 2 == 0: print(0)
    else: print(g)
