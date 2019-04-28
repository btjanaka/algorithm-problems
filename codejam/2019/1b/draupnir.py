# Author: btjanaka (Bryon Tjanaka)
# Problem: (Google Code Jam) Draupnir
# (small input only)
import numpy as np
import sys

def grab(i):
    print(i)
    sys.stdout.flush()
    return int(input())

t,w = map(int, input().split())
for _ in range(t):
    d = [grab(i) for i in range(1, 7)]
    matrix = np.array([
        [2, 1, 1, 1, 1, 1],
        [4, 2, 1, 1, 1, 1],
        [8, 2, 2, 1, 1, 1],
        [16, 4, 2, 2, 1, 1],
        [32, 4, 2, 2, 2, 1],
        [64, 8, 4, 2, 2, 2],
    ])
    sol = np.linalg.solve(matrix, np.array(d))
    print(d)
    print(' '.join([str(int(round(x))) for x in sol]))
    sys.stdout.flush()
    if int(input()) == -1: break
