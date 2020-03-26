# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) shashank-and-list
# Title: Shashank and List
# Link: https://www.hackerrank.com/challenges/shashank-and-list/problem
# Idea: Use the idea that (a+1)(b+1)(c+1) - 1 = a + b + c + ab + ac + bc + abc.
# We can take 2^a_i for each element in the list, then apply the extended
# version of this formula.
# Difficulty: medium
# Tags: math
from functools import reduce
MOD = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
a = list(map(lambda a: (pow(2, a, MOD) + 1) % MOD, a))
tot = reduce(lambda a, b: (a * b) % MOD, a, 1)
print((tot - 1) % MOD)
