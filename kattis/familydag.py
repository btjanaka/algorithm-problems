# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) familydag
# Title: Family DAG
# Link: https://open.kattis.com/problems/familydag
# Idea: Build the graph, and run a BFS starting at each member. If we find the
# same family member more than once (i.e. we already visited them) we can set
# the original member to hillbilly or paradox.
# Difficulty: medium
# Tags: graph

import sys
from collections import defaultdict
from collections import deque

first = True
while True:
    try:
        # Input the graph
        g = defaultdict(list)
        while True:
            line = input().strip()
            if line == "done": break
            tok = line.split()
            g[tok[2]].append(tok[0])
            g[tok[0]]  # Make sure all family members are initialized
        status = {a: None for a in g}

        # Run BFS at each node
        for a in g:
            q = deque([a])
            visited = set()
            visited.add(a)
            while len(q) > 0:
                u = q.popleft()
                for v in g[u]:
                    if v in visited:
                        # We already saw this family member, so |a| is either
                        # hillbilly or paradox. Careful about setting it - if
                        # they are already a paradox, we do not want to make
                        # them hillbilly.
                        status[a] = "paradox" if a == v or status[
                            a] == "paradox" else "hillbilly"
                    else:
                        q.append(v)
                        visited.add(v)

        # Output
        if first:
            first = False
        else:
            print()
        for name, s in sorted(filter(lambda x: x[1] is not None,
                                     status.items())):
            print(f"{name} {s}")
    except EOFError:
        break
