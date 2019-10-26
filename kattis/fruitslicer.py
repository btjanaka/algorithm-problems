# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) fruitslicer
# Title: Fruit Slicer
# Link: https://open.kattis.com/problems/fruitslicer
# Idea: For every pair of points, calculate the distance from every other point
# to the line passing between these two points. Make sure distance is signed, so
# that points on one side of the line are negative distance while points on the
# other side are positive distance. Then, sort the points by distance to the
# line and use a sliding window to find the largest interval where
# distance[end] - distance[start] <= 2.0 (since each fruit has radius 1).
# Credits: Arne Philipeit (https://github.com/arneph)
# Difficulty: hard
# Tags: computational-geometry

from math import sqrt
from collections import defaultdict


def calc_dist_to_line(p, a, b):
    """Distance from point p to line passing between a and b. Distance is
    signed, so that points on one side are negative distance while points on
    other side are positive distance.

    See https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line#Line_defined_by_two_points
    """
    x0, y0 = p
    x1, y1 = a
    x2, y2 = b
    return ((y2 - y1) * x0 -
            (x2 - x1) * y0 + x2 * y1 - y2 * x1) / sqrt((y2 - y1)**2 +
                                                       (x2 - x1)**2)


n = int(input())
coords = [tuple(map(float, input().split())) for _ in range(n)]

# Count the occurrences of each point, so that we consider that
# the best slice could go through these points alone
counts = defaultdict(int)
for c in coords:
    counts[c] += 1

res = max(counts.values())

for i in range(n):
    for j in range(i + 1, n):
        # There's no line between these points if they are the same point, and
        # distance calculation fails anyway (Division by zero)
        if coords[i] == coords[j]: continue

        # Calculate distance from every point to line parallel to this one but
        # passing through origin
        distances = [calc_dist_to_line(c, coords[i], coords[j]) for c in coords]
        distances.sort()

        # Find the largest window where the points are within 2.0 of the line -
        # O(n) time
        start, end = 0, 0
        while end != n:
            if distances[end] - distances[start] > 2.0:
                start += 1
            else:
                end += 1
                res = max(res, end - start)

print(res)
