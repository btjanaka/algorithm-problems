# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) brexitnegotiations
# Title: Brexit Negotiations
# Link: https://open.kattis.com/problems/brexitnegotiations
# Idea: Use a topological sort starting from the back and prioritizing nodes
# with the smallest e[i]. We can't go from the front because that is _too_
# greedy - there are cases where we choose the largest e[i] and it doesn't work.
# Difficulty: medium
# Tags: topological-sort, graph
from collections import defaultdict
from heapq import *

n = int(input())

g = [[] for _ in range(n + 1)]
e = [0 for _ in range(n + 1)]
in_deg = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    tokens = list(map(int, input().split()))
    e[i] = tokens[0]
    d = tokens[1]
    for j in range(d):
        u = tokens[2 + j]
        g[i].append(u)
        in_deg[u] += 1

# Topological sort from back and prioritize choosing ones with smaller e.
q = []
for i in range(1, n + 1):
    if in_deg[i] == 0:
        heappush(q, (e[i], i))

covered = n - 1
mx = 0
while covered >= 0:
    cost, cur = heappop(q)
    mx = max(mx, covered + cost)
    covered -= 1
    for v in g[cur]:
        in_deg[v] -= 1
        if in_deg[v] == 0:
            heappush(q, (e[v], v))

print(mx)
