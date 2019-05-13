# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 452
# Title: Project Scheduling
# Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=393
# Idea: Shortest path algorithm in a DAG - find topological ordering then go
# through and relax all edges - O(E) time.
# Difficulty: easy
# Tags: DAG, topological-sort, shortest-path

import sys
from collections import defaultdict
from collections import deque

ca = int(input())
input()

for caa in range(ca):
    g = defaultdict(set)
    cost = defaultdict(int)
    indeg = defaultdict(int)
    while True:
        try:
            line = input().strip()
        except EOFError:
            break

        if line == "": break
        tokens = line.split()
        if len(tokens) == 2:
            v, c = tokens
            incoming = ""
        else:
            v, c, incoming = tokens
        cost[v] = -int(c)
        indeg[v] = len(incoming)
        for u in incoming:
            g[u].add(v)
            g[v]

    # topo sort
    topo = []
    q = deque()
    dist = {u: 1 << 31 for u in g}
    for u in indeg:
        if indeg[u] == 0:
            q.append(u)
            dist[u] = cost[u]
    while len(q) > 0:
        u = q.popleft()
        topo.append(u)
        for v in g[u]:
            indeg[v] -= 1
            if indeg[v] == 0: q.append(v)

    # find min
    for u in topo:
        for v in g[u]:
            dist[v] = min(dist[v], dist[u] + cost[v])

    print(-min(dist.values()))
    if caa != ca - 1: print()
