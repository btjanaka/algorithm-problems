# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2020-1a-pascal-walk
# Title: Pascal Walk
# Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
# Idea: Since the i-th row of Pascal's triangle sums to 2^(i-1), we can
# represent n as a binary number and choose to traverse rows that correspond to
# the 1's digits of n. This almost works, except that we are forced to traverse
# the 1's in the rows we don't want to. To counter this, we can solve the
# problem for n - 30 instead, and add on any extra 1's that we need at the end.
# Why 30? Because n <= 10^9, and 2^30 > 10^9, so we only need the first 30 rows
# of the triangle. See the analysis at the problem link for more info.
# Difficulty: hard
# Tags: math, bit-manipulation
for ca in range(1, int(input()) + 1):
    n = int(input())
    print("Case #{}:".format(ca))
    if n <= 30:
        # Special case for n <= 30
        for i in range(n):
            print(i + 1, i + 1)
    else:
        # Find rows for n - 30
        n2 = n - 30
        n2bin = bin(n2)[2:][::-1]
        tot = 0
        side = True  # Changes every time we cross a row
        for row in range(len(n2bin)):
            if n2bin[row] == '1':
                tot += 1 << row
                for col in (range(row + 1) if side else range(row, -1, -1)):
                    print(row + 1, col + 1)
                side = not side
            else:
                tot += 1
                # Print a different '1' cell based on where we are
                print(row + 1, 1 if side else row + 1)
        if tot < n:
            for row in range(len(n2bin), n - tot + len(n2bin)):
                print(row + 1, 1 if side else row + 1)
