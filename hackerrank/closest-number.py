# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) closest-number
# Title: Closest Number
# Link: https://www.hackerrank.com/challenges/closest-number/problem
# Idea: a^b can only be 10^9 at most, so just take the power p and subtract p %
# x. Make sure to also check if the next multiple is closer.
# Difficulty: easy
# Tags: math
for _ in range(int(input())):
    a, b, x = map(int, input().split())
    p = pow(a, b)
    ans = int(p - (p % x))
    # Check whether it is better to go above.
    if ans + x - p < p - ans:
        ans += x
    print(ans)
