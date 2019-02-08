# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 10226
from collections import defaultdict
import sys

n = int(input().strip())
count = 0
input()
first = True
trees = defaultdict(int)
for line in sys.stdin:
    line = line.strip()
    if line == "":
        if first:
            first = False
        else:
            print()
        for tree in sorted(trees):
            print(f"{tree} {trees[tree] / count * 100.0:.4f}")
        trees = defaultdict(int)
        count = 0
    else:
        trees[line] += 1
        count += 1

if first:
    first = False
else:
    print()
for tree in sorted(trees):
    print(f"{tree} {trees[tree] / count * 100.0:.4f}")
