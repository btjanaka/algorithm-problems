# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) whatdoesthefoxsay
t = int(input().strip())
for i in range(t):
    words = input().strip().split()
    sounds = set()
    line = input().strip()
    while line != "what does the fox say?":
        sounds.add(line.split()[2])
        line = input().strip()
    first = True
    for w in words:
        if w not in sounds:
            if first:
                first = False
            else:
                print(" ", end="")
            print(w, end="")
    print()
