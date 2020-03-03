# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) string-construction
# Title: String Construction
# Link: https://www.hackerrank.com/challenges/string-construction/problem
# Idea: Since you can copy any substring at no charge, you can just copy single
# letters that you previously purchased. Thus, the cost is equal to the number
# of unique letters in your string.
# Difficulty: easy
# Tags: strings
for _ in range(int(input())):
    print(len(set(input().strip())))
