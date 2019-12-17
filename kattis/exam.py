# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) exam
# Title: Exam
# Link: https://open.kattis.com/problems/exam
# Idea: Count the number of questions where you matched your friend. You want as
# many of these as possible to be correct. If k is less than the number of same,
# you got (same - k) questions wrong for sure. If k is greater than the number
# of same, you got (k - same) questions wrong because on those ones, you put a
# different answer than your friend.
# Difficulty: easy
# Tags: math

k = int(input())
a, b = input().strip(), input().strip()

same = 0
different = 0
for c, d in zip(a, b):
    if c == d:
        same += 1
    else:
        different += 1

max_correct = same + different - abs(k - same)
print(max_correct)
