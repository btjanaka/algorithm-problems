# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 382
# Title: Linked List Random Node
# Link: https://leetcode.com/problems/linked-list-random-node/
# Idea: See Reservoir Sampling on Wikipedia: https://en.wikipedia.org/wiki/Reservoir_sampling
# Difficulty: medium
# Tags: linked-list, random

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from random import randint


class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head_ = head

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        itr = self.head_
        val = itr.val

        i = 2
        itr = itr.next
        while itr != None:
            j = randint(1, i)
            if j == 1:
                val = itr.val
            i += 1
            itr = itr.next
        return val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
