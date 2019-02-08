# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 10686
import sys
n = int(input())
for ca in range(n):
    # 0: category, 1: p, 2: keywords
    cats = []
    words = set()
    c = int(input())
    for i in range(c):
        tokens = input().strip().split()
        cats.append((tokens[0], int(tokens[2]), set()))
        for i in range(int(tokens[1])):
            w = input().strip()
            cats[-1][2].add(w)

    # Input lines
    while True:
        try:
            line = input().strip()
            if line == "": break
            clean = ""
            for ch in line:
                if ch in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
                    clean += ch
                else:
                    clean += ' '
            for w in clean.split():
                words.add(w)
        except EOFError:
            break

    first = True
    for cat in cats:
        tot = 0
        for w in cat[2]:
            if w in words: tot += 1
        if tot >= cat[1]:
            if first:
                first = False
            else:
                print(',', end='')
            print(cat[0], end='')
    if first:
        print('SQF Problem.', end='')
    print()
