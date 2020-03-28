# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) triangle-numbers
# Title: Triangle Numbers
# Link: https://www.hackerrank.com/challenges/triangle-numbers/problem
# Idea: Try solving the first 10 rows or so by hand to quickly see a pattern.
# (No need to solve the entire row, just the first four numbers or so of each
# row.)
# Difficulty: easy
# Tags: math, ad-hoc
for _ in range(int(input())):
    n = int(input())
    if n == 1 or n == 2:
        # First two rows never have even numbers.
        print(-1)
    elif n % 4 == 0:
        print(3)
    elif n % 2 == 0:
        print(4)
    else:
        # Odd rows always have an even number in the second position.
        print(2)
