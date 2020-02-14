# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) checkingforcorrectness
# Title: Checking for Correctness
# Link: https://open.kattis.com/problems/checkingforcorrectness
# Idea: Use Python :p
# Difficulty: medium
# Tags: math

import sys
from collections import defaultdict

for line in sys.stdin:
    a, op, b = line.strip().split()
    a, b = int(a), int(b)
    if op == "+":
        print((a + b) % 10000)
    elif op == "*":
        print((a * b) % 10000)
    else:
        # Take advantage of Python's third arg to `pow`
        print(pow(a, b, 10000))
