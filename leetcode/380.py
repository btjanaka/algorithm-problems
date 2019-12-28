# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 380
# Title: Insert Delete GetRandom O(1)
# Link: https://leetcode.com/problems/insert-delete-getrandom-o1/
# Idea: Use a dictionary and a list together. The list allows you to perform
# random selection, while the dictionary lets you keep track of what items are
# currently being used. Insertion is simply appending to the list, and removal
# is simply swapping with the back and popping.
# Difficulty: medium
# Tags: random, data-structures
from random import choice


class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.D = {}  # Tracks indices of items in the list
        self.L = []  # Enables random selection

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.D: return False
        self.L.append(val)
        self.D[val] = len(self.L) - 1
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.D: return False
        idx = self.D[val]
        self.L[idx], self.L[-1] = self.L[-1], self.L[
            idx]  # Swap with last element
        self.D[self.L[idx]] = idx  # Update former last element's index
        self.L.pop()  # Then remove
        del self.D[val]
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return choice(self.L)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
