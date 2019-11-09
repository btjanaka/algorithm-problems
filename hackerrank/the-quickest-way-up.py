# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) the-quickest-way-up
# Title: Snakes and Ladders: The Quickest Way Up
# Link: https://www.hackerrank.com/challenges/the-quickest-way-up/problem
# Idea: Store a graph as a 1D array mapping each position to the position one
# would actually go to - for instance if there is a ladder at square 35 going to
# square 99, we set g[35] = 99. Then, perform a BFS on this graph.
# Difficulty: medium
# Tags: bfs, shortest-paths
from collections import deque

t = int(input())
for ca in range(t):
    # Initially, there are no special routes in the squares
    g = [i for i in range(101)]

    # Take in snakes and ladders
    n = int(input())
    for _ in range(n):
        u, v = map(int, input().split())
        g[u] = v
    m = int(input())
    for _ in range(m):
        u, v = map(int, input().split())
        g[u] = v

    # BFS to find the solution
    solution = -1
    q = deque()
    visited = [False for i in range(101)]
    q.append((1, 0))
    visited[1] = True
    while len(q) > 0:
        u, d = q.popleft()
        if u == 100:
            solution = d
            break
        for i in range(1, 7):
            if u + i > 100: continue
            v = g[u + i]
            if not visited[v]:
                q.append((v, d + 1))
                visited[v] = True
    print(solution)
