# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 398
# Title: Random Pick Index
# Link: https://leetcode.com/problems/random-pick-index/
# Idea: Store all positions and take a random choice. This takes a lot of memory
# though. Alternatively, you could randomly keep picking indices until you find
# one that works? That is O(n) runtime though.
# Difficulty: medium
# Tags: random
import random
from collections import defaultdict


class Solution:

    def __init__(self, nums: List[int]):
        self.positions = defaultdict(list)
        for idx, x in enumerate(nums):
            self.positions[x].append(idx)

    def pick(self, target: int) -> int:
        return random.choice(self.positions[target])


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
