# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) xrange-and-pizza
# Title: Xrange's Pancakes
# Link: https://www.hackerrank.com/challenges/xrange-and-pizza/problem
# Idea: Measure rotation in clockwise ticks. Count rotations as normal. Flips
# induce a rotation of k ticks in the opposite direction. At the end, use either
# a flip or a rotate to turn the pancake to its initial orientation.
# Difficulty: easy
# Tags: geometry
n, m = map(int, input().split())
clockwise_rotation, is_flipped = 0, False
for _ in range(m):
    op, k = map(int, input().split())
    if op == 1:
        # Rotation
        if is_flipped:
            clockwise_rotation = (clockwise_rotation + k) % n
        else:
            clockwise_rotation = (clockwise_rotation - k) % n
    else:
        # Flip
        if is_flipped:
            clockwise_rotation = (clockwise_rotation - k) % n
        else:
            clockwise_rotation = (clockwise_rotation + k) % n
        is_flipped = not is_flipped

# At the end, clockwise_rotation should be 0, and is_flipped should be False.
if is_flipped:
    # Flip (which induces a rotation).
    print(f"2 {clockwise_rotation}")
else:
    # Rotate.
    print(f"1 {clockwise_rotation}")
