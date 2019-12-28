# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 381
# Title: Insert Delete GetRandom O(1) - Duplicates allowed
# Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
# Idea: Refer to my solution to LeetCode 380 (https://github.com/btjanaka/
# Extending that solution to cover duplicate elements is not too hard -- you
# just have to maintain a set of indices for each value, instead of a single
# index.
# Difficulty: medium
# Tags: random, data-structures
from random import choice
from collections import defaultdict


class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.D = defaultdict(
            set)  # Tracks a set of indices of each item in the list
        self.L = []  # Enables random selection

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        self.L.append(val)
        self.D[val].add(len(self.L) - 1)

        # If the set length is 1, it was not already there
        return len(self.D[val]) == 1

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.D or len(self.D[val]) == 0: return False
        idx = None
        for i in self.D[val]:  # Get an index
            idx = i
            break
        self.L[idx], self.L[-1] = self.L[-1], self.L[idx]
        self.D[val].remove(idx)  # Remove the element's position

        # Sometimes the last element is being removed
        if idx != len(self.L) - 1:
            self.D[self.L[idx]].remove(
                len(self.L) - 1)  # Remove the former last element's position
            self.D[self.L[idx]].add(idx)  # Update former last element's index

        self.L.pop()  # Remove from list
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return choice(self.L)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
