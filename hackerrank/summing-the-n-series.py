# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) summing-the-n-series
# Title: Summing the N series
# Link: https://www.hackerrank.com/challenges/summing-the-n-series/problem
# Idea: The terms cancel out such that the sum is just n^2.
# Difficulty: easy
# Tags: math
t = int(input())
MOD = 10**9 + 7
for i in range(t):
    n = int(input()) % MOD
    print((n * n) % MOD)
