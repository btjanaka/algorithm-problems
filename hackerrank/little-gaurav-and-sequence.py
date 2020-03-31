# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) little-gaurav-and-sequence
# Title: Little Gaurav and Sequence
# Link: https://www.hackerrank.com/challenges/little-gaurav-and-sequence/problem
# Idea: There are several steps: 1) Separate the powers so that you have
# 2^(2^i) * 4^j. Now you can move the 2^(2^i) outside of the inner summation and
# see that the inner summation is just \sum_{j=0}^n 4^n = (4^(n+1)-1)/3
# (summation of geometric series). Furthermore, this turns out to be a constant
# that multiplies the rest of the expression. 2) There is one trick that we need
# for taking this summation. (4^(n+1)-1)/3 is far too large for Python to
# calculate, so we have to take it modulo 10. But to do division modulo 10, we
# need to find the modular inverse of 3, which is 7 (see
# https://www.geeksforgeeks.org/modular-division/). Now we can calculate
# (4^(n+1)-1)*7 % 10 -- we use modulos on the other parts of the expression as
# well. 3) Now we need to sum up \sum_{i=0,2^i<=n}^{\infty} 2^(2^i). We can
# replace 2^i<=n with i <= floor(log(n,2)), so that we do not need to calculate
# large powers. Note that since n <= 10**15, we only need ~50 steps, which is
# certainly manageable.
# Difficulty: medium
# Tags: math
from math import log, floor
for _ in range(int(input())):
    n = int(input())

    # - Python's built-in `pow` function can take powers modulo a certain value.
    # - We multiply by 7 instead of dividing by 3.
    j_sum = ((pow(4, n + 1, 10) - 1) % 10 * 7) % 10

    # Sum up \sum_{i=0,2^i<=n}^{\infty} 2^(2^i).
    i_sum = 0
    i = 0
    limit = floor(log(n, 2))  # Easier limit to use.
    # Instead of recalculating 2^(2^i) each time, we keep a running value and
    # square it to get the next value.
    two_to_two_to_i = 2  # 2^(2^0)
    while i <= limit:
        i_sum = (i_sum + two_to_two_to_i) % 10
        two_to_two_to_i = (two_to_two_to_i**2) % 10
        i += 1
    print((i_sum * j_sum) % 10)
