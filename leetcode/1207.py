# Author: btjanaka (Bryon Tjanaka)
# Problem: (Leetcode) 1207
# Title: Unique Number of Occurrences
# Link: https://leetcode.com/problems/unique-number-of-occurrences/
# Idea: Simply count the occurrences.
# Difficulty: easy
# Tags: set, list
from collections import defaultdict


class Solution(object):

    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        occ = defaultdict(int)
        for x in arr:
            occ[x] += 1
        return len(occ) == len(set(occ.values()))
