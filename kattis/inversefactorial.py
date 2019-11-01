# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) inversefactorial
# Title: Inverse Factorial
# Link: https://open.kattis.com/problems/inversefactorial
# Idea: We can't calculate any factorials directly since n is so big, so we have
# to instead look at the log. The number of digits in a number in base b is
# ceil(log_{b} (n)). We can calculate the number of digits in n! by summing the
# log_10 (1) ... log_10(n). We know the number of digits in n! is unique except
# for small n (< 10ish), so we can just keep adding up the log of the next n
# until we get the correct number of digits.
# Difficulty: medium
# Tags: math
from math import log, ceil, factorial

while True:  # <-- allows us to take multiple inputs for easier testing
    s = None
    try:
        s = input().strip()
    except EOFError:
        break
    digits = len(s)

    small = [str(factorial(i)) for i in range(1, 10)]
    if s in small:
        # The small factorials have many conflicts, so just brute force check
        # them here.
        print(small.index(s) + 1)
    else:
        # Keep checking number of digits.
        n = 10
        tot = log(factorial(10), 10)
        while ceil(tot) != digits:
            n += 1
            tot += log(n, 10)
        print(n)
