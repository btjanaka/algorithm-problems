# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 973
# Title: K Closest Points to Origin
# Link: https://leetcode.com/problems/k-closest-points-to-origin/
# Idea: Sort the points by their squared distance to the origin and return the
# first K
# Difficulty: Easy
# Tags: computational-geometry
class Solution:

    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return sorted(points, key=lambda p: p[0]**2 + p[1]**2)[:K]
