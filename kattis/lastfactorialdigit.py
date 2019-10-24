# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) lastfactorialdigit
# Title: Last Factorial Digit
# Link: https://open.kattis.com/problems/lastfactorialdigit
# Idea: Just do as it says.
# Difficulty: easy
# Tags: math

from math import factorial
n = int(input())
for _ in range(n):
    k = int(input())
    print(factorial(k) % 10)
