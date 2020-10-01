# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) little-chammys-huge-donation
# Title: Little Ashish's Huge Donation
# Link: https://www.hackerrank.com/challenges/little-chammys-huge-donation/problem
# Idea: Since there is a closed formula we can use to calculate the sum of
# squares from 1 to n, we can binary search for the number of children that can
# be fed.
# Difficulty: medium
# Tags: math, binary-search


def sqsum(n):
    """"
    Calculates 6 * (sum of numbers from 1 to n) (we want to avoid division
    for large numbers because Python is not good with it). See
    https://trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
    """
    return n * (n + 1) * (2 * n + 1)


for _ in range(int(input())):
    x = 6 * int(input())  # To avoid division in sqsum
    lo, hi = 0, 10**9
    while hi - lo > 1:
        mid = (hi + lo) // 2
        s = sqsum(mid)
        if s < x:
            lo = mid
        elif s > x:
            hi = mid
        else:
            lo = mid
            hi = mid
            break
    print(lo)
