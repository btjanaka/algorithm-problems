# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) robotopia
# Title: Robotopia
# Link: https://open.kattis.com/problems/robotopia
# Idea: This is just solving a system of linear equations. But since there are a
# lot of constraints here, it is easiest to brute force through all possible
# values. Keep in mind the solution must contain two positive integers.
# Difficulty: medium
# Tags: math, complete-search
for _ in range(int(input())):
    l1, a1, l2, a2, lt, at = tuple(map(int, input().split()))
    solutions = 0
    sol = None
    for x in range(1, 10001):
        y = (lt - (l1 * x)) / l2
        if y > 0 and y.is_integer():
            y = round(y)
            if a1 * x + a2 * y == at:
                solutions += 1
                sol = (x, y)
    print(f"{sol[0]} {sol[1]}" if solutions == 1 else "?")
