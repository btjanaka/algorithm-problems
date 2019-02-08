# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 10446

import sys

dp = [[-1 for _ in range(61)] for _ in range(61)]


def f(n, back):
    if n <= 1: return 1
    if dp[n][back] != -1: return dp[n][back]

    dp[n][back] = 1
    for i in range(1, back + 1):
        dp[n][back] += f(n - i, back)
    return dp[n][back]


ca = 1
for line in sys.stdin:
    n, back = tuple(map(int, line.strip().split()))
    if n > 60: break
    print(f"Case {ca}: {f(n, back)}")
    ca += 1
