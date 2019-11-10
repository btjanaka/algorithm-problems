# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 478
# Title: Generate Random Point in a Circle
# Link: https://leetcode.com/problems/generate-random-point-in-a-circle/
# Idea: See https://programming.guide/random-point-within-circle.html
# Difficulty: medium
# Tags: geometry
import random
import math


class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.x0 = x_center
        self.y0 = y_center
        self.r = radius

    def randPoint(self) -> List[float]:
        theta = random.random() * 2 * math.pi
        d = math.sqrt(random.random()) * self.r
        return [self.x0 + d * math.cos(theta), self.y0 + d * math.sin(theta)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
