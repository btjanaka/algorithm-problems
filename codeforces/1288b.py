# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeForces) 1288b
# Title: Yet Another Meme Problem
# Link: https://codeforces.com/contest/1288/problem/B
# Idea: We can represent the conc operation as
# conc(a,b) = a * 10^ceil(log(b,10)) + b. We can then solve
# ab + a + b = conc(a,b) to get b + 1 = 10^ceil(log(b,10)). Thus, a can be any
# value, as long as b consists only of 9's (9, 99, 999, etc.)
# Difficulty: easy
# Tags: math

import sys
from collections import defaultdict

for _ in range(int(input())):
    a, b = map(int, input().split())

    n_nines = 0
    itr = 9
    while itr <= b:
        n_nines += 1
        itr = itr * 10 + 9

    print(n_nines * a)
