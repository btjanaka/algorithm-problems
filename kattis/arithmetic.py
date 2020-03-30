# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) arithmetic
# Title: Arithmetic
# Link: https://open.kattis.com/problems/arithmetic
# Idea: Convert base 8 to base 16.
# Difficulty: easy
# Tags: math, implementation

print(hex(int(input().strip(), base=8))[2:].upper())
