# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) glyphrecognition
# Title: Glyph Recognition
# Link: https://open.kattis.com/problems/glyphrecognition
# Idea: Use binary search to find polygons which match the criteria given in the
# problem. We search for the inner and the outer polygons and check the ratio.
# Note: USE PYTHON 2 for submitting this problem - Kattis's version of Python 3
# is too slow.
# Difficulty: medium
# Tags: implementation, computational-geometry

import sys
from collections import defaultdict
from math import sqrt, sin, cos, pi


class Point:

    def __init__(self, x, y):
        self.x = x
        self.y = y


def is_within_polygon(polygon, point):
    """
    See https://algorithmtutor.com/Computational-Geometry/Check-if-a-point-is-inside-a-polygon/
    """
    A = []
    B = []
    C = []
    for i in range(len(polygon)):
        p1 = polygon[i]
        p2 = polygon[(i + 1) % len(polygon)]

        # calculate A, B and C
        a = -(p2.y - p1.y)
        b = p2.x - p1.x
        c = -(a * p1.x + b * p1.y)

        A.append(a)
        B.append(b)
        C.append(c)

    D = []
    for i in range(len(A)):
        d = A[i] * point.x + B[i] * point.y + C[i]
        D.append(d)

    t1 = all(d >= 0 for d in D)
    t2 = all(d <= 0 for d in D)
    return t1 or t2


def count_points_within_polygon(k, r, pts):
    """
    Counts the number of points in |pts| that are within the polygon with k sides and
    radius r.
    """
    polygon = []
    delta_theta = 2 * pi / k
    for i in range(k):
        polygon.append(Point(r * cos(i * delta_theta),
                             r * sin(i * delta_theta)))
    #  print(polygon)
    return sum(is_within_polygon(polygon, p) for p in pts)


def find_inner_radius(k, pts):
    """
    Finds radius of largest inner polygon that contains none of the points using
    binary search.
    """
    hi = 1e9
    lo = 0.0
    mid = None
    while hi - lo > 1e-9:
        mid = (hi + lo) / 2.0
        num_points_within = count_points_within_polygon(k, mid, pts)
        if num_points_within == 0:
            lo = mid
        else:
            hi = mid
    return mid


def find_outer_radius(k, pts):
    """
    Finds radius of smallest outer polygon that contains all of the points using
    binary search.
    """
    hi = 1e9
    lo = 0.0
    mid = None
    while hi - lo > 1e-9:
        mid = (hi + lo) / 2.0
        num_points_within = count_points_within_polygon(k, mid, pts)
        if num_points_within == n:
            hi = mid
        else:
            lo = mid
    return mid


def polygon_area(k, r):
    """
    Finds area for polygon with k sides and radius r.
    See https://www.mathopenref.com/polygonregulararea.html.
    """
    return r * r * k * sin(2 * pi / k) / 2


# Driver
while True:
    try:
        # Input the points
        n = input()
        pts = []
        for _ in range(n):
            x, y = map(float, raw_input().split())
            pts.append(Point(x, y))

        # Try out all possible polygons
        max_score = -1.0
        max_k = 0
        for k in range(3, 9):
            a_inner = polygon_area(k, find_inner_radius(k, pts))
            a_outer = polygon_area(k, find_outer_radius(k, pts))
            score = a_inner / a_outer
            if score > max_score:
                max_score = score
                max_k = k
        print("{max_k} {max_score:.9f}".format(max_k=max_k,
                                               max_score=max_score))
    except EOFError:
        break
