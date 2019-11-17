# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 90
# Title: Subsets II
# Link: https://leetcode.com/problems/subsets-ii/
# Idea: Currently just generating all the subsets and then using a set to remove
# duplicates. There is definitely a better way, but this is simple I suppose.
# Difficulty: medium
# Tags: sets
class Solution:

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        n = len(nums)
        for i in range(1 << n):
            cur = []
            for j in range(n):
                if i & (1 << j):
                    cur.append(nums[j])
            res.append(tuple(cur))
        return list(set(res))
