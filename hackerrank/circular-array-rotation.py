# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) circular-array-rotation
n, k, q = map(int, input().split())
nums = list(map(int, input().split()))
for _ in range(q):
    m = int(input())
    print(nums[(m - k) % n])
