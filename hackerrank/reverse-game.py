# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) reverse-game
# Title: Reverse Game
# Link: https://www.hackerrank.com/challenges/reverse-game/problem
# Idea: Manually calculate the positions for an even and odd N, say 6, and 5,
# and you will see a pattern. Numbers >= n // 2 end up at indices 0,2,... in
# descending order, while the others end up at indices 1,3,... in ascending
# order.
# Difficulty: easy
# Tags: math
for _ in range(int(input())):
    n, k = map(int, input().split())
    if k >= n // 2:
        print((n - k - 1) * 2)
    else:
        print(k * 2 + 1)
