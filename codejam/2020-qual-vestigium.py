# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2020-qual-vestigium
# Title: Vestigium
# Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
# Idea: Implement the problem using sets and by iterating through the array by
# row or by column.
# Difficulty: easy
# Tags: implementation
for case in range(int(input())):
    n = int(input())
    m = [list(map(int, input().split())) for _ in range(n)]
    # Calculate trace.
    k = sum(m[i][i] for i in range(n))
    # Check rows.
    r = 0
    for row in m:
        el = set()
        has_repeat = False
        for x in row:
            if x in el:
                has_repeat = True
            el.add(x)
        r += has_repeat
    # Check columns.
    c = 0
    for i in range(n):
        el = set()
        has_repeat = False
        for j in range(n):
            x = m[j][i]
            if x in el:
                has_repeat = True
            el.add(x)
        c += has_repeat
    print("Case #" + str(case + 1) + ":", k, r, c)
