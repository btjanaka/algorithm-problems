# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) abc
# Title: ABC
# Link: https://open.kattis.com/problems/abc
# Idea: Implementation
# Difficulty: easy
# Tags: implementation
A, B, C = sorted(map(int, input().split()))
print(' '.join(str(eval(ch)) for ch in input().strip()))
