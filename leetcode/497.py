# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 497
# Title: Random Point in Non-overlapping Rectangles
# Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
# Idea: First choose a rectangle, then choose a point within that rectangle.
# Weight the choice of rectangle by its area, and make the choice of point
# within the rectangle a random uniform choice.
# Difficulty: medium
# Tags: random, probability

import random
from bisect import bisect_right


class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects

        # This is essentially a CDF giving cutoffs for p when choosing
        # rectangles.
        self.weights = [(r[2] - r[0] + 1) * (r[3] - r[1] + 1) for r in rects]
        for i in range(1, len(rects)):  # Accumulation weights.
            self.weights[i] += self.weights[i - 1]
        total_weight = self.weights[-1]
        initial_weight = self.weights[0]
        # Normalize each weight.
        for i in range(len(rects)):
            self.weights[i] = self.weights[i] / total_weight
        # Prepend 0.0 to complete the CDF. The weights now look something like
        # [0.0, 0.13, 0.26, ..., 0.8, 1.0]
        self.weights.insert(0, 0.0)

    def pick(self) -> List[int]:
        # Choose a probability and find where it belongs in the CDF.
        p = random.random()
        chosen_rectangle = bisect_right(self.weights, p) - 1

        # With the rectangle chosen, pick a point within it at random. Keep in
        # mind randint(a,b) selects an integer x such that a <= x <= b
        r = self.rects[chosen_rectangle]
        return [random.randint(r[0], r[2]), random.randint(r[1], r[3])]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
