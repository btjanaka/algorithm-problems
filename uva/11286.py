# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 11286
from collections import defaultdict

while True:
    n = int(input())
    if n == 0: break
    combos = defaultdict(int)
    for i in range(n):
        courses = map(int, input().strip().split())
        combos[tuple(sorted(courses))] += 1
    mx_combo = combos[max(combos, key=lambda x: combos[x])]
    tot = sum(combos[c] for c in combos if combos[c] == mx_combo)
    print(tot)
