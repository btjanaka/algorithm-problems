# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) non-divisible-subset
from collections import defaultdict

n, k = map(int, input().strip().split())
nums = list(map(int, input().strip().split()))
mods = defaultdict(int)
for x in nums:
    mods[x % k] += 1

tot = min(mods[0], 1)
for i in range(1, k // 2):
    tot += max(mods[i], mods[k - i])
if k % 2 == 0:
    tot += min(mods[k // 2], 1)
elif k != 1:
    tot += max(mods[k // 2], mods[k // 2 + 1])
print(tot)
