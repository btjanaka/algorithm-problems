# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) circular-array-rotation
# Title: Circular Array Rotation
# Link: https://www.hackerrank.com/challenges/circular-array-rotation/problem
# Idea: Use modulos.
# Difficulty: easy
# Tags: array
n, k, q = map(int, input().split())
nums = list(map(int, input().split()))
for _ in range(q):
    m = int(input())
    print(nums[(m - k) % n])
