# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 247

import sys
from collections import defaultdict


def kosaraju(g, g_rev):
    order = []
    visited = set()

    def visit(u):
        visited.add(u)
        for v in g[u]:
            if v not in visited:
                visit(v)
        order.append(u)

    for u in g:
        if u not in visited: visit(u)

    components = []
    visited.clear()

    def build_comp(u):
        components[-1].append(u)
        visited.add(u)
        for v in g_rev[u]:
            if v not in visited:
                build_comp(v)

    for u in order[::-1]:
        if u not in visited:
            components.append([])
            build_comp(u)

    return components


def main():
    case = 1
    while True:
        # input
        n, m = map(int, input().split())
        if n == 0 and m == 0: break
        g, g_rev = defaultdict(set), defaultdict(set)
        for _ in range(m):
            u, v = input().strip().split()
            g[u].add(v)
            g[v]
            g_rev[v].add(u)
            g_rev[u]

        # output
        if case != 1: print()
        print(f"Calling circles for data set {case}:")
        for c in kosaraju(g, g_rev):
            print(", ".join(c))

        case += 1


main()
