# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) a-chocolate-fiesta
# Title: A Chocolate Fiesta
# Link: https://www.hackerrank.com/challenges/a-chocolate-fiesta/problem
# Idea: Count up the number of even and odd numbers n_even and n_odd. Then, the
# answer is the number of ways to select a subset of the even numbers multiplied
# by the number of ways to select a subset of even size of the odd numbers. The
# first quantity is just 2^n_even, while the second one is 2^n_odd / 2 =
# 2^(n_odd-1) (We can take a look at Pascal's triangle to see this is true; if
# we have any row and we want to look at xC0, xC2, xC4,... we can see that
# selecting item 0,2,4,... always ends gives us half of the row's sum). After
# multiplying these two quantities, we subtract 1 for the case of an empty set.
# Difficulty: medium
# Tags: math, combinatorics
MOD = 10**9 + 7

n = int(input())
nums = list(map(int, input().split()))
n_even = 0
n_odd = 0
for x in nums:
    if x % 2 == 0:
        n_even += 1
    else:
        n_odd += 1

odd_combos = 1 if n_odd == 0 else pow(2, n_odd - 1, MOD)
even_combos = pow(2, n_even, MOD)
print(((odd_combos * even_combos) % MOD - 1) % MOD)
