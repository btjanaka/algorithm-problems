# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) hackerland-radio-transmitters
# Title: Hackerland Radio Transmitters
# Link: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
# Idea: This is a greedy interval covering problem. We know that all houses have
# to be covered eventually, so we advance along the houses from left to right,
# placing transmitters as far to the right as we can.
# Difficulty: medium
# Tags: greedy
n, k = tuple(map(int, input().split()))
pos = sorted(map(int, input().split()))  # Make sure to sort
tot = 0
i = 0

while i < n:
    # |left| is the leftmost house that we now need to cover. We advance along
    # the houses until we find a house that would not be able to cover this
    # leftmost house.
    left = pos[i]
    while i < n and pos[i] - left <= k:
        i += 1
    # Radio gets placed at the previous house position, as it was the last house
    # that was within k of |left|
    radio = pos[i - 1]
    tot += 1
    # Now that we have placed a radio, we see how many more houses we happened
    # to cover by placing the radio here.
    while i < n and pos[i] - radio <= k:
        i += 1
print(tot)
