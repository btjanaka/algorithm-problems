# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) strong-password
# Title: Strong Password
# Link: https://www.hackerrank.com/challenges/strong-password/problem
# Idea: Count the number of each type of character, and add up the difference.
# If we still don't satisfy the length requirement, add the difference.
# Difficulty: easy
# Tags: implementation
numbers = set("0123456789")
lower_case = set("abcdefghijklmnopqrstuvwxyz")
upper_case = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
special_characters = set("!@#$%^&*()-+")

input()
s = input()
counts = {
    "numbers": 0,
    "lower_case": 0,
    "upper_case": 0,
    "special_characters": 0
}
for ch in s:
    if ch in numbers:
        counts["numbers"] += 1
    elif ch in lower_case:
        counts["lower_case"] += 1
    elif ch in upper_case:
        counts["upper_case"] += 1
    elif ch in special_characters:
        counts["special_characters"] += 1

needed = 0
for item, count in counts.items():
    if count == 0: needed += 1
if len(s) + needed < 6:
    needed += 6 - len(s) - needed
print(needed)
