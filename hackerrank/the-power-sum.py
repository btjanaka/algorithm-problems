# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) the-power-sum
# Title: The Power Sum
# Link: https://www.hackerrank.com/challenges/the-power-sum/problem
# Idea: See function |f| in the code. We just need to memoize this function and
# call it properly.
# Difficulty: medium
# Tags: math, dynamic-programming
import functools


@functools.lru_cache(5000)  # built-in DP table :D
def f(x, i, n):
    if x < 0: return 0
    if x == 0: return 1
    if i == 0: return 0
    return f(x, i - 1, n) + f(x - i**n, i - 1, n)


x = int(input())
n = int(input())
print(f(x, 32, n))
