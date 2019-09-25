# Author: btjanaka (Bryon Tjanaka)
# Problem: (Leetcode) 1
# Title: Two Sum
# Link: https://leetcode.com/problems/two-sum/
# Idea: The easy solution is to check every pair of elements, but this is
# O(n^2). To achieve O(n), the basic idea is to use a set that keeps track of
# which elements we have seen so far while iterating through the list. Then, for
# the value x, we can check if we have (target - x) in the set. This is
# efficient since lookups for a hash set are O(1). In this solution, we have to
# use a dict / hash map instead of a set because we need to store the indices of
# the numbers.
# Difficulty: easy
# Tags: set
class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prev_nums_with_indices = dict()
        for i in range(len(nums)):
            x = nums[i]
            if (target - x) in prev_nums_with_indices:
                prev_num_index = prev_nums_with_indices[target - x]
                return [prev_num_index, i]
            prev_nums_with_indices[x] = i
        # Technically not necessary, since the problem guarantees exactly one solution.
        return [-1, -1]
