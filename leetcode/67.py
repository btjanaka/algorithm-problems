# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 67
# Title: Add Binary
# Link: https://leetcode.com/problems/add-binary/
# Idea: Could implement it, but can also call library functions :D
# Difficulty: easy
# Tags: math
class Solution:

    def addBinary(s, a, b):
        return bin(int(a, 2) + int(b, 2))[2:]
