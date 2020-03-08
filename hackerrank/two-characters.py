# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) two-characters
# Title: Two Characters
# Link: https://www.hackerrank.com/challenges/two-characters/problem
# Idea: Brute force -- for all possible pairs of letters, check if we get a
# string of alternating letters by only extracting those letters from `s`.
# Difficulty: easy
# Tags: string, implementation
from string import ascii_lowercase as alphabet

# Input.
input()
s = input().strip()

# Iterate through all possible pairs of characters and find maximum
# length possible.
mx = 0
for ch1 in alphabet:
    for ch2 in alphabet:
        # Characters must be different.
        if ch1 == ch2: continue

        # Filter out only ch1 and ch2.
        filtered = [ch for ch in s if ch == ch1 or ch == ch2]
        if len(filtered) <= 1: continue  # Too short.

        # Check if alternating characters are all different.
        if all(a1 != a2 for a1, a2 in zip(filtered[:-1], filtered[1:])):
            mx = max(mx, len(filtered))
print(mx)
