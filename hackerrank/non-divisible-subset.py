# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) non-divisible-subset
# Title: Non-Divisible Subset
# Link: https://www.hackerrank.com/challenges/non-divisible-subset/problem
# Idea: The sum of a pair of numbers x1, x2 is divisible by k iff
# (x1%k) + (x2%k) == k. Hence, if we have numbers that, when modded by k, come
# out to a value i, we cannot also have numbers that, when modded by k, result
# in (k-i). Thus, we have to choose the maximum between i and k-i for all values
# in [i, k//2) (roughly -- see code).
# Difficulty: medium
# Tags: implementation
from collections import defaultdict

n, k = map(int, input().strip().split())
nums = list(map(int, input().strip().split()))
mods = defaultdict(int)
for x in nums:
    mods[x % k] += 1

tot = min(mods[0], 1)  # At most one value can mod to 0.
for i in range(1, k // 2):
    # Choose between i and k - i.
    tot += max(mods[i], mods[k - i])
if k % 2 == 0:
    # If even, we can have at most one number x s.t. x % k = k // 2.
    tot += min(mods[k // 2], 1)
elif k != 1:
    # If odd, we can choose from the two middle values.
    tot += max(mods[k // 2], mods[k // 2 + 1])
print(tot)
