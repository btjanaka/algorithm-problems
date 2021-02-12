# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) equal-stacks
# Title: Equal Stacks
# Link: https://www.hackerrank.com/challenges/equal-stacks/problem
# Idea: Calculate the cumulative sums of the items in two of the stacks. Then
# check which sums are in all 3 stacks as we iterate through the third stack.
# Difficulty: easy
# Tags: map
n1, n2, n3 = map(int, input().split())
s1 = list(map(int, input().split()))
s2 = list(map(int, input().split()))
s3 = list(map(int, input().split()))

m2 = {0}
cum = 0
for i in range(n2 - 1, -1, -1):
    cum += s2[i]
    m2.add(cum)

m3 = {0}
cum = 0
for i in range(n3 - 1, -1, -1):
    cum += s3[i]
    m3.add(cum)

cum = 0
mx = 0
for i in range(n1 - 1, -1, -1):
    cum += s1[i]
    if cum in m2 and cum in m3:
        mx = cum
print(mx)
