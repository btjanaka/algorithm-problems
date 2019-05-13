# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) frosting
# Title: Frosting on the Cake
# Link: https://open.kattis.com/problems/frosting
# Idea: There is a pattern with which cells are colored yellow, pink, and white
# in each column. We can sum up the lengths of the cells which are always the same
# color and multiply them by the width as we go across.
# Difficulty: medium
# Tags: math, geometry
import sys
from collections import defaultdict

n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))
mod = [0] + [sum(b[i::3]) for i in range(1, 4)]

yellow, pink, white = 0, 0, 0
for i in range(1, n + 1):
    yellow += mod[3 - i % 3] * a[i]
    pink += mod[3 - (i + 2) % 3] * a[i]
    white += mod[3 - (i + 1) % 3] * a[i]
print(yellow, pink, white)
