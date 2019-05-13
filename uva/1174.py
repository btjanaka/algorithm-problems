# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 1174
# Title: IP-TV
# Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3615
# Idea: Implement your favorite MST (Minimum Spanning Tree) algorithm.
# Difficulty: easy
# Tags: MST

import heapq
import sys
from collections import defaultdict

ca = int(input())

for caa in range(ca):
    # input
    input()
    m = int(input())
    n = int(input())
    g = defaultdict(list)
    for _ in range(n):
        u, v, c = input().split()
        c = int(c)
        g[u].append((v, c))
        g[v].append((u, c))

    # Prim's
    in_graph = set()
    tot = 0
    pq = []
    for x in g:
        pq.append((0, x))
        break
    while len(in_graph) < n and len(pq) > 0:
        cost, u = heapq.heappop(pq)
        if u in in_graph: continue
        in_graph.add(u)
        tot += cost
        for v, c in g[u]:
            if v not in in_graph: heapq.heappush(pq, (c, v))

    print(tot)
    if caa < ca - 1: print()
