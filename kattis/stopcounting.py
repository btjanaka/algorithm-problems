# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) stopcounting
# Title: Stop Counting
# Link: https://open.kattis.com/problems/stopcounting
# Idea: We know we can eliminate any single range of cards and take the average
# of the remaining. In reality, this problem boils down to selecting a range of
# cards at either the beginning or the end that maximizes our average (i.e.,
# either pick the first k cards or last k cards). We _could_ choose both sides
# if the average stays the same, but we are not asked to specify what range we
# chose anyway. Hence, we simply calculate averages as we go from left to right
# and right to left, and find the place where the average is maximized.
# Difficulty: medium
# Tags: dynamic-programming, range-sum
n = int(input())

a = list(map(int, input().split()))

# Cumulative sum from left and right
ls = [0 for _ in range(n)]
rs = [0 for _ in range(n)]
for i in range(n):
    ls[i] = a[i] + (0 if i == 0 else ls[i - 1])
for i in range(n - 1, -1, -1):
    rs[i] = a[i] + (0 if i == n - 1 else rs[i + 1])

# Average from left and right
left_avgs = [ls[i] / (i + 1) for i in range(n)]
right_avgs = [rs[i] / (n - i) for i in range(n - 1, -1, -1)]

# Consider 0 in case everything is negative
print(max(max(left_avgs), max(right_avgs), 0))
