# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) bday-gift
# Title: B'day Gift
# Link: https://www.hackerrank.com/challenges/bday-gift/problem
# Idea: We sum up the expected value of each step to get the final expected
# value. The expected value of each step is 0.5 * price
# Difficulty: easy
# Tags: math, probability
print(f"{sum(int(input()) for _ in range(int(input())))/2:.1f}")
