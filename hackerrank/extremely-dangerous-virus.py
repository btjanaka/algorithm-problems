# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) extremely-dangerous-virus
# Title: Extremely Dangerous Virus
# Link: https://www.hackerrank.com/challenges/extremely-dangerous-virus/problem
# Idea: Use exponential growth with the expected growth rate (a + b) / 2 at each
# time step.
# Difficulty: medium
# Tags: math, probability
a, b, t = map(int, input().split())
print(pow((a + b) // 2, t, 10**9 + 7))
