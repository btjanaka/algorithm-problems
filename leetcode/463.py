# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 463
# Title: Island Perimeter
# Link: https://leetcode.com/problems/island-perimeter/
# Idea: We can add 1 to the perimeter whenever we find a 1 cell bordering a 0
# cell.
# Difficulty: easy
# Tags: array, grid
class Solution:

    def islandPerimeter(self, grid: List[List[int]]) -> int:
        # Augment the grid with a ring of 0's around it.
        n, m = len(grid) + 2, len(grid[0]) + 2
        grid = [[0 for _ in range(m)]] + [[0] + row + [0] for row in grid
                                         ] + [[0 for _ in range(m)]]

        # Search for all 0 cells. When we find a 0 cell, we add one to the total
        # perimeter for every 1 cell touching that 0 cell.
        perimeter = 0
        DR = [0, 0, -1, 1]
        DC = [-1, 1, 0, 0]
        for r in range(n):
            for c in range(m):
                if grid[r][c] == 1: continue
                for dr, dc in zip(DR, DC):
                    r2 = r + dr
                    c2 = c + dc
                    if r2 >= 0 and r2 < n and c2 >= 0 and c2 < m:
                        if grid[r2][c2] == 1: perimeter += 1
        return perimeter
