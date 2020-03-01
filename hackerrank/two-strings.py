# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) two-strings
# Title: Two Strings
# Link: https://www.hackerrank.com/challenges/two-strings/problem
# Idea: Since one-character substrings count, we just need to check whether
# there are any characters that are in both A and B. This is equivalent to
# checking if the intersection of the set of characters in A and the set of
# characters in B is empty.
# Difficulty: easy
# Tags: strings
for _ in range(int(input())):
    print('NO' if (set(input().strip()) &
                   set(input().strip()) == set()) else 'YES')
