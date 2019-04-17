# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) summing-the-n-series
t = int(input())
MOD = 10**9 + 7
for i in range(t):
    n = int(input()) % MOD
    print((n * n) % MOD)
