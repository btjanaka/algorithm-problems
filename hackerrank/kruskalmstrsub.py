# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) kruskalmstrsub
# Title: Kruskal(MST): Really Special Subtree
# Link: https://www.hackerrank.com/challenges/kruskalmstrsub/problem
# Idea: Implement Kruskal's algorithm.
# Difficulty: easy
# Tags: mst, graph

#
# Data Structure
#


class UnionFind:

    def __init__(self, n):
        self.rank = [0 for _ in range(n)]
        self.parent = [i for i in range(n)]

    def find(self, i):
        if self.parent[i] == i:
            return i
        else:
            self.parent[i] = self.find(self.parent[i])
            return self.parent[i]

    def same(self, i, j):
        return self.find(i) == self.find(j)

    def join(self, i, j):
        if not self.same(i, j):
            x = self.find(i)
            y = self.find(j)
            if self.rank[x] > self.rank[y]:
                self.parent[y] = x
            else:
                self.parent[x] = y
                if self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
            return True
        return False


#
# Driver Code
#

# Input.
n, e = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(e)]  # u, v, weight

# Sort the edges first by weight, then by u + v + weight.
edges.sort(key=lambda x: (x[2], x[0] + x[1] + x[2]))

# Create a UnionFind data structure to keep track of which nodes are joined
# together so far. We make it with size |n + 1| because the graph's nodes are
# numbered starting at 1.
uf = UnionFind(n + 1)

# Add in all the edges.
final_cost = 0
for u, v, weight in edges:
    if uf.join(u, v):
        final_cost += weight

# Output.
print(final_cost)
