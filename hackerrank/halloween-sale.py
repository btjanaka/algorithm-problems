# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) halloween-sale
# Title: Halloween Sale
# Link: https://www.hackerrank.com/challenges/halloween-sale/problem
# Idea: The problem is small enough to brute force.
# Difficulty: easy
# Tags: implementation, math
p, d, m, s = map(int, input().split())
i = 0
while s >= 0:
    s -= max(p - d * i, m)
    i += 1
print(i - 1)
