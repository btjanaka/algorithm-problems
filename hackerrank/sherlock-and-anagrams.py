# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) sherlock-and-anagrams
# Title: Sherlock and Anagrams
# Link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
# Idea: Find all substrings of the string, sort their characters, and put them
# into a dictionary to see how many times each one occurs. Then go through the
# entries (string, count) and add up (count choose 2) = count * (count - 1) / 2.
# (count choose 2) is the number of pairs that can be made for each unique
# anagram substring.
# Difficulty: medium
# Tags: strings, math
from collections import defaultdict

for _ in range(int(input())):
    s = input().strip()
    n = len(s)

    # Count how many times each substring occurs.
    subs = defaultdict(int)
    for i in range(n):
        for j in range(i + 1, n + 1):
            subs[''.join(sorted(s[i:j]))] += 1

    # Count up pairs.
    tot = 0
    for _, k in subs.items():
        tot += k * (k - 1) // 2

    print(tot)
