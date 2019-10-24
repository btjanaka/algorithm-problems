# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) unique-dice
# Title: Unique Dice
# Link: https://open.kattis.com/problems/uniquedice
# Idea: Brute force - load in every possible rotation of the dice and see what
# has the most hits. Make sure to use Python 2 on Kattis for this since Kattis
# Python 3 is old and slow.
# Difficulty: medium
# Tags: brute-force, complete-search

from collections import defaultdict

n = input()
rotations = defaultdict(set)
for i in range(n):
    d = map(int, raw_input().strip().split())

    for j in range(6):
        # j tells which face should be rotated to the top
        top, bot, front, back, left, right = d
        e = None
        if j == 0:
            # Top
            e = [top, bot, front, back, left, right]
        elif j == 1:
            # Bottom
            e = [bot, top, back, front, left, right]
        elif j == 2:
            # Front
            e = [front, back, bot, top, left, right]
        elif j == 3:
            # Back
            e = [back, front, top, bot, left, right]
        elif j == 4:
            # Left
            e = [left, right, front, back, bot, top]
        elif j == 5:
            # Right
            e = [right, left, front, back, top, bot]
        top, bot, front, back, left, right = tuple(range(6))
        for _ in range(4):
            # Try all 4 rotations with this face at the top
            e[front], e[back], e[left], e[right] = e[right], e[left], e[
                front], e[back]
            rotations[tuple(e)].add(i)

print(max(len(die) for die in rotations.values()))
