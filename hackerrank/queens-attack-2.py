# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) queens-attack-2
# Title: Queen's Attack II
# Link: https://www.hackerrank.com/challenges/queens-attack-2/problem
# Idea: Brute force -- check all 8 directions to see how many squares the queen
# can attack.
# Difficulty: medium
# Tags: implementation
import sys
from collections import defaultdict

n, k = map(int, input().strip().split())
qr, qc = map(int, input().strip().split())

# store occupied columns on each row
obstacles = defaultdict(set)

for _ in range(k):
    r, c = map(int, input().strip().split())
    obstacles[r].add(c)

count = 0
dr = [1, 1, 1, 0, 0, -1, -1, -1]
dc = [1, 0, -1, 1, -1, 1, 0, -1]
for d in range(8):
    cur = [qr, qc]
    while True:
        cur[0] += dr[d]
        cur[1] += dc[d]
        if cur[0] > n or cur[0] <= 0 or cur[1] > n or cur[1] <= 0 or \
            (cur[0] in obstacles and cur[1] in obstacles[cur[0]]):
            break
        count += 1

print(count)
