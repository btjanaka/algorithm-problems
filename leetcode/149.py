# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 149
from math import gcd
from fractions import Fraction
from collections import defaultdict


class Solution:

    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) == 1: return 1
        mx = 0
        for x1, y1 in points:
            line_counts = defaultdict(int)
            for x2, y2 in points:
                if x1 == x2 and y1 == y2: continue
                if x1 == x2:
                    line_counts[1, 0, 0, 0] += 1
                    continue  # vertical line
                m = Fraction(y2 - y1, x2 - x1)
                m /= gcd(m.numerator, m.denominator)
                b = y2 - m * x2
                line_counts[(m.numerator, m.denominator, b.numerator,
                             b.denominator)] += 1
            count = 0 if len(line_counts) == 0 else max(line_counts.values())
            mx = max(count + points.count([x1, y1]), mx)
        return mx
