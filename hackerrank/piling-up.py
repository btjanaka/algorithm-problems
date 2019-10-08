# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) piling-up
# Title: Piling Up!
# Link: https://www.hackerrank.com/challenges/piling-up/problem
# Idea: Keep picking the largest cube (choose between left and right) that will
# fit on the stack. We succeed if we can use up all cubes.
# Difficulty: medium
# Tags: deque, greedy
from collections import deque

cases = int(input())
for _ in range(cases):
    # Key input/output trick in Python
    n = int(input())
    nums = deque(map(int, input().strip().split()))
    # Continuously pick the larger of the two cubes that will fit, until we can
    # no longer satisfy the conditions.
    prev = max(nums[0], nums[-1])
    while len(nums) > 0:
        left_is_ok = nums[0] <= prev
        right_is_ok = nums[-1] <= prev
        if left_is_ok and right_is_ok:
            # If both sides are ok, pop the larger one
            if nums[0] > nums[-1]:
                nums.popleft()
            else:
                nums.pop()
        elif left_is_ok:
            nums.popleft()
        elif right_is_ok:
            nums.pop()
        else:
            print("No")
            break
    else:
        print("Yes")
