# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) sparse-arrays
# Title: Sparse Arrays
# Link: https://www.hackerrank.com/challenges/sparse-arrays/problem
# Idea: Store the number of occurrences of each item in a dict. I suppose you
# could use a trie but it's a lot more code.
# Difficulty: easy
# Tags: arrays
from collections import defaultdict

n = int(input())
strings = defaultdict()
for _ in range(n):
    strings[input().strip()] += 1
q = int(input())
for _ in range(q):
    print(strings[input().strip()])
