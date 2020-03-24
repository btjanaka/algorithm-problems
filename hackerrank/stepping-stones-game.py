# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) stepping-stones-game
# Title: Stepping Stones Game
# Link: https://www.hackerrank.com/challenges/stepping-stones-game/problem
# Idea: The sum of the arithmetic series 1,2,.. is n(n+1)/2. If the Nth block is
# reachable, then n(n+1)/2 = N will have a whole number solution. This equation
# is quadratic; we can obtain n^2 + n - 2N = 0 by rearranging. We then apply the
# quadratic formula to get that the one positive solution is
# n = -1 + sqrt(1 + 8N) / 2. If n is a whole number, Bob wins.
# Difficulty: easy
# Tags: math
from math import sqrt
for _ in range(int(input())):
    N = int(input())
    n = (-1 + sqrt(1 + 8 * N)) / 2
    if abs(round(n) - n) < 1e-9:
        print("Go On Bob", round(n))
    else:
        print("Better Luck Next Time")
