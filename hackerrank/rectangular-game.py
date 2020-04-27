# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) rectangular-game
# Title: Rectangular Game
# Link: https://www.hackerrank.com/challenges/rectangular-game/problem
# Idea: We need to find the dimensions of the smallest rectangle covered by all
# of the rectangles in the input. We do this by finding the minimum values of
# each dimension.
# Difficulty: easy
# Tags: geometry
x, y = 10**9, 10**9
for _ in range(int(input())):
    a, b = map(int, input().split())
    x, y = min(a, x), min(b, y)
print(x * y)
