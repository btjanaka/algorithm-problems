# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) p1-paper-cutting
# Title: Cutting Paper Squares
# Link: https://www.hackerrank.com/challenges/p1-paper-cutting/problem
# Idea: Minimum between cutting one way and the other.
# Difficulty: easy
# Tags: geometry
n, m = map(int, input().split())
print(min(m - 1 + m * (n - 1), n - 1 + n * (m - 1)))
