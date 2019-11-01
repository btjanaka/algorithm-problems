# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) anewalphabet
# Title: A New Alphabet
# Link: https://open.kattis.com/problems/anewalphabet
# Idea: Use a dictionary to implement translation.
# Difficulty: easy
# Tags: implementation, annoying
d = {
    'a': '@',
    'b': '8',
    'c': '(',
    'd': '|)',
    'e': '3',
    'f': '#',
    'g': '6',
    'h': '[-]',
    'i': '|',
    'j': '_|',
    'k': '|<',
    'l': '1',
    'm': '[]\\/[]',
    'n': '[]\\[]',
    'o': '0',
    'p': '|D',
    'q': '(,)',
    'r': '|Z',
    's': '$',
    't': '\'][\'',
    'u': '|_|',
    'v': '\\/',
    'w': '\\/\\/',
    'x': '}{',
    'y': '`/',
    'z': '2'
}

s = input().strip().lower()
print(''.join(d[a] if a in d else a for a in s))
