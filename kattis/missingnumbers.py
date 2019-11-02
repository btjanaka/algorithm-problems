# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) missingnumbers
# Title: Missing Numbers
# Link: https://open.kattis.com/problems/missingnumbers
# Idea: Keep counting.
# Difficulty: easy
# Tags: implementation

n = int(input())
cur = 1
num_printed = 0
for _ in range(n):
    k = int(input())
    while cur < k:
        num_printed += 1
        print(cur)
        cur += 1
    cur = k + 1
if num_printed == 0: print("good job")
