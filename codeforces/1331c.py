# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeForces) 1331c
# Title: ...And after happily lived ever they
# Link: https://codeforces.com/contest/1331/problem/C
# Idea: Look at the order of the words in the title, then rearrange the 6 bits
# in each number accordingly -- specifically bit 0,5,3,2,4,1.
# Difficulty: easy
# Tags: april-fools
import sys

for line in sys.stdin:
    a = int(line)
    b = bin(a)[2:]
    while len(b) < 6:
        b = "0" + b
    print(int(b[0] + b[5] + b[3] + b[2] + b[4] + b[1], base=2))
