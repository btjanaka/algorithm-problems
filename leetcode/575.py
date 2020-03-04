# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 575
# Title: Distribute Candies
# Link: https://leetcode.com/problems/distribute-candies/
# Idea: The sister can receive at most n/2 different candies, or the number of
# different kinds of candies.
# Difficulty: easy
# Tags: array
class Solution:

    def distributeCandies(self, candies: List[int]) -> int:
        return min(len(candies) // 2, len(set(candies)))
