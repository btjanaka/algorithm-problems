# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) 4thought
# Title: 4 thought
# Link: https://open.kattis.com/problems/4thought
# Idea: You could use math, or you could brute force -- there's only 64
# equations :p
# Difficulty: easy
# Tags: math

# Pre-calculate all the solutions
ops = ["+", "-", "*", "/"]
solutions = {}
for a in ops:
    for b in ops:
        for c in ops:
            s = " ".join(("4", a, "4", b, "4", c, "4")).replace("/", "//")
            n = eval(s)
            solutions[n] = s.replace("//", "/") + f" = {n}"

t = int(input())
for _ in range(t):
    n = int(input())
    print(solutions[n] if n in solutions else "no solution")
