# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2019-1b-draupnir
# Title: Draupnir
# Link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/0000000000122837
# Idea: See the analysis in the problem link.
# Difficulty: hard
# Tags: math
import sys


def grab(i):
    print(i)
    sys.stdout.flush()
    return int(input())


t, w = map(int, input().split())
for _ in range(t):
    q200, q56 = grab(200), grab(56)
    r6 = (q200 % (1 << 40)) // (1 << 33)
    r5 = (q200 % (1 << 50) - (r6 * (1 << 33))) // (1 << 40)
    r4 = (q200 - r5 * (1 << 40) - r6 * (1 << 33)) // (1 << 50)
    rem = q56 - r6 * (1 << 9) - r5 * (1 << 11) - r4 * (1 << 14)
    r3 = (rem % (1 << 28)) // (1 << 18)
    r2 = (rem % (1 << 56) - (r3 * (1 << 18))) // (1 << 28)
    r1 = (rem - r2 * (1 << 28) - r3 * (1 << 18)) // (1 << 56)
    print(r1, r2, r3, r4, r5, r6)
    sys.stdout.flush()
    if int(input()) == -1: break
