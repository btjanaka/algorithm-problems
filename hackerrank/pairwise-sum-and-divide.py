# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) pairwise-sum-and-divide
# Title: Pairwise Sum and Divide
# Link: https://www.hackerrank.com/challenges/pairwise-sum-and-divide/problem
# Idea: Realize that floor((a+b)/ab) = floor((a+b)/ab) if a = 1 or b = 1, 1 if a
# = b = 2, 0 otherwise. Thus, we only really need to account for the 1's and 2's
# in our calculation of the sum. See code for how exactly we do that.
# Difficulty: medium
# Tags: math
from math import floor

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    num_ones = sum(1 for x in a if x == 1)
    num_twos = sum(1 for x in a if x == 2)

    tot = 0

    # Add on 2 for every pair of ones (using the formula for n chooose 2)
    tot += num_ones * (num_ones - 1)

    # Perform one sweep to see how much a single 1 would get when combined
    # with all the other numbers.
    single_one = sum(floor((1 + x) / x) for x in a if x != 1)
    tot += single_one * num_ones

    # Add on 1 for every pair of twos
    tot += num_twos * (num_twos - 1) // 2

    print(tot)
