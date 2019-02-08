# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 10018
n = int(input().strip())
for i in range(n):
    p = int(input().strip())
    count = 0
    while str(p) != str(p)[::-1]:
        p += int(str(p)[::-1])
        count += 1
    print(f"{count} {p}")
