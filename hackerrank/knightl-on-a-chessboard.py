# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) knightl-on-a-chessboard
# Title: KnightL on a Chessboard
# Link: https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
# Idea: Use a BFS starting at (0,0) and keep trying moves until we run out or
# reach (n-1,n-1).
# Difficulty: medium
# Tags: bfs, shortest-path, sssp
from collections import deque


# Performs BFS starting at (0,0).
def knightMoves(a, b, n):
    q = deque()
    visited = [[False for x in range(n)] for y in range(n)]

    q.append(((0, 0), 0))
    visited[0][0] = True

    dx = [-a, +a, -a, +a, -b, +b, -b, +b]
    dy = [-b, -b, +b, +b, -a, -a, +a, +a]

    while len(q) > 0:
        cur, dist = q.popleft()
        y, x = cur

        if y == n - 1 and x == n - 1: return dist

        # Iterate through all possible moves, throwing out ones that go to
        # out-of-bounds or previously visited squares.
        for i in range(len(dx)):
            y2 = y + dy[i]
            x2 = x + dx[i]
            if x2 < 0 or x2 >= n or y2 < 0 or y2 >= n: continue
            if visited[y2][x2]: continue
            visited[y2][x2] = True
            q.append(((y2, x2), dist + 1))

    return -1


# Driver code - takes in input and runs all the necessary combos of a and b.
n = int(input())
for a in range(1, n):
    res = []
    for b in range(1, n):
        res.append(str(knightMoves(a, b, n)))
    print(" ".join(res))
