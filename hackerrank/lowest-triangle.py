# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) lowest-triangle
# Title: Minimum Height Triangle
# Link: https://www.hackerrank.com/challenges/lowest-triangle/problem
# Idea: Use the formula for area of a triangle, a = (1/2)bh
# Difficulty: easy
# Tags: math, geometry
import math

b, a = map(int, input().split())
print(math.ceil(2 * a / b))
