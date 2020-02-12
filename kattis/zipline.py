# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) zipline
# Title: Zipline
# Link: https://open.kattis.com/problems/zipline
# Idea: The minimum length is easy; it's just the distance between the tops of
# the two poles. The maximum length is a bit trickier. We know that we want to
# find the shortest line that dips to |r| above the ground at its lowest point.
# When the rider rides on this zipline, they will be more than |r| above the
# ground until the lowest point.
#
# We can find the length of this line as follows. First, chop off |r| from both
# poles. We end up with the following scenario:
#
#                    xx|
#     |xx         xx   |
# g-r |   xx   xx      | h-r
#     |______x_________|
#              w
#
# We can now vertically reflect the diagonal line on the right, to end up with:
#
#     A
#     |xx
# g-r |   xx
#     |______x__________
#              xx      |
#                 xx   | h-r
#                    xx|
#                      B
#
# Now, it is trivial to see that the shortest line goes directly between the
# points A and B (the tips of the two poles labeled above). This length is the
# Euclidean distance between A and B, i.e. sqrt(w^2 + (g+h-2r)^2)
#
# Difficulty: medium
# Tags: computational-geometry, math

from math import sqrt

for _ in range(int(input())):
    w, g, h, r = map(float, input().split())

    min_length = sqrt((h - g)**2 + w**2)
    max_length = sqrt(w**2 + (h + g - 2 * r)**2)

    print(min_length, max_length)
