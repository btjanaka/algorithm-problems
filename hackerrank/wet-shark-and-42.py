# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) wet-shark-and-42
# Title: Wet Shark and 42
# Link: https://www.hackerrank.com/challenges/wet-shark-and-42/problem
# Idea: Count the number of cycles by dividing s by 42, then add in the distance
# that Wet Shark gets from the remaining energy. There is a slight discontinuity
# since if rem = 0, wet shark can't pass the next multiple of 42.
# Difficulty: easy
# Tags: math
MOD = 10**9 + 7
for _ in range(int(input())):
    energy_per_cycle = (42 - 2) // 2
    s = int(input())
    cycles = s // energy_per_cycle
    rem = s % energy_per_cycle
    print((cycles * 42 + (-2 if rem == 0 else rem * 2)) % MOD)
