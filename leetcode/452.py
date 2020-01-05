# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 452
# Title: Minimum Number of Arrows to Burst Balloons
# Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
# Idea: Represent the horizontal coordinates as a series of "events" telling
# when each balloon starts and ends. Sort these events by their position and go
# through them. Keep track of a list of balloons that are currently being
# covered; when we find an end event, we know we have to pop everything, so we
# mark all balloons in our list as popped and empty the list.
# Difficulty: medium
# Tags: list, sorting
class Solution:

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        events = []  # position of event, 0 (start) or 1 (end), index
        for i in range(len(points)):
            events.append((points[i][0], 0, i))
            events.append((points[i][1], 1, i))
        events.sort()

        popped = [False for _ in range(len(points))]
        cur = []  # Current list of spheres that will be popped
        arrows = 0
        for pos, t, i in events:
            if t == 0:  # Start
                cur.append(i)
            elif t == 1:  # End
                if popped[i]: continue  # Avoid re-popping
                arrows += 1
                # Mark all as popped
                while len(cur) > 0:
                    popped[cur.pop()] = True

        return arrows
