# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) yinyangstones

stoneSeq = input()
total = 0

for c in stoneSeq:
    if c == "B":
        total += 1
    else:
        total -= 1

if total == 0:
    print(1)
else:
    print(0)
