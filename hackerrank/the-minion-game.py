# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) the-minion-game
# Title: The Minion Game
# Link: https://www.hackerrank.com/challenges/the-minion-game/
# Idea: The basic idea is to count all substrings for each player, but we can't
# just list out all the substrings because that is O(n^2), and the string can be
# of length 10^6 here. A more efficient way is to recognize that there are
# len(string) - i substrings that start at any index i (0-based), so if the
# character at index i is a vowel, we count len(string) - i additional
# substrings that start with vowels.
# Difficulty: Medium
# Tags: list, math, string
def minion_game(string):
    consonants = 0
    vowels = 0
    for i in range(len(string)):
        score = len(string) - i
        if string[i] in "AEIOU":
            vowels += score
        else:
            consonants += score

    if consonants > vowels:
        print(f"Stuart {consonants}")
    elif consonants < vowels:
        print(f"Kevin {vowels}")
    else:
        print("Draw")


if __name__ == '__main__':
    s = input()
    minion_game(s)
