# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) yinyangstones
# Title: Yin and Yang Stones
# Link: https://open.kattis.com/problems/yinyangstones
# Idea: Somehow if the number of black and white stones is equal, it works.
# Difficulty: easy
# Tags: ad-hoc, math

stoneSeq = input()
total = 0

for c in stoneSeq:
    if c == "B":
        total += 1
    else:
        total -= 1

if total == 0:
    print(1)
else:
    print(0)
