# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 587
# Title: Erect the Fence
# Link: https://leetcode.com/problems/erect-the-fence/
# Idea: Apply the convex hull algorithm, but allow the hull to contain straight
# lines (i.e. let the orientation be <= 0 instead of strictly < 0)
# Difficulty: Medium
# Tags: convex-hull, computational-geometry
class Solution:

    def orientation(self, a, b, c):
        # orientation test:
        # | ax ay 1 |
        # | bx by 1 |
        # | cx cy 1 |
        x, y = 0, 1
        return a[x] * b[y] - a[x] * c[y] - a[y] * b[x] + a[y] * c[x] + b[x] * c[
            y] - b[y] * c[x]

    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
        chosen = set()
        points.sort()

        # calculate upper hull
        stack = []
        for p in points:
            while len(stack) >= 2 and self.orientation(stack[-2], stack[-1],
                                                       p) > 0:
                stack.pop()
            stack.append(p)
        for p in stack:
            chosen.add(tuple(p))

        # calculate lower hull
        stack = []
        points = points[::-1]  # reverse the points
        for p in points:
            while len(stack) >= 2 and self.orientation(stack[-2], stack[-1],
                                                       p) > 0:
                stack.pop()
            stack.append(p)
        for p in stack:
            chosen.add(tuple(p))

        return [list(p) for p in chosen]
