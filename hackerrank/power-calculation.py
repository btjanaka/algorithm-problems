# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) power-calculation
# Title: Power Calculation
# Link: https://www.hackerrank.com/challenges/power-calculation/problem
# Idea: Since the question asks for the last two digits, we need to mod the
# final answer by 100. We can distribute this mod 100 over the entire summation
# using various mod rules. Furthermore, we realize that
# k^n mod 100 = (k mod 100)^n mod 100, which means that we only have 100 unique
# bases (0-99) that we need to raise to the power of n. We can multiply the sum
# of the powers of those unique bases as appropriate.
# Difficulty: medium
# Tags: math
for _ in range(int(input())):
    k, n = map(int, input().split())
    cumsum = [0 for _ in range(100)]  # Cumulative sum from 0^n to 99^n
    for i in range(1, 100):
        cumsum[i] = (cumsum[i - 1] + pow(i, n, 100)) % 100
    # Count how many times we repeat the sum from 0 to 99, and count the remainder
    whole, rem = k // 100, k % 100
    tot = (((whole % 100) * cumsum[99]) % 100 + cumsum[rem]) % 100
    print(f"{tot:02d}")
