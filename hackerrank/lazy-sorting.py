# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) lazy-sorting
# Title: Lazy Sorting
# Link: https://www.hackerrank.com/challenges/lazy-sorting/problem
# Idea: Count the number of permutations q that are considered "sorted" by taking
# the number of total permutations (n!) and dividing by the factorial of the
# frequency of each item (i.e. the number of ways that identical elements can be
# rearranged, e.g. if 3 appears 4 times, we divide by 4!). The probability of
# randomly choosing a sorted item is 1/q, so we have a geometric distribution. The
# expected wait time of a geometric distribution with probability p is 1/p, so
# our final answer is just 1 / (1/q) = q. Don't forget to check if the sequence
# is already sorted.
# Difficulty: medium
# Tags: sorting, probability, math
from collections import defaultdict
from math import factorial

n = int(input())
p = list(map(int, input().split()))
if p == sorted(p):
    print("0.000000")
else:
    freq = defaultdict(int)
    for x in p:
        freq[x] += 1
    tot = factorial(n)
    for x in freq.values():
        tot /= factorial(x)
    print("%.6f" % tot)
