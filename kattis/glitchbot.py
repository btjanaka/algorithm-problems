# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) glitchbot

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def works(mvs, xf, yf) -> bool:
    d = 0
    x, y = 0, 0
    for m in mvs:
        if m == "Right": d = (d + 1) % 4
        elif m == "Left": d = (d - 1) % 4
        else:
            x += dx[d]
            y += dy[d]
    return x == xf and y == yf


while True:
    line = None
    try:
        line = input()
    except:
        break

    x, y = tuple(map(int, line.split()))
    n = int(input().strip())

    mvs = []
    for i in range(n):
        mvs.append(input().strip())
    mvs2 = list(mvs)

    ok = False
    for i in range(n):
        for m in ["Right", "Left", "Forward"]:
            if m != mvs[i]:
                mvs2[i] = m
                if works(mvs2, x, y):
                    print(f"{i + 1} {m}")
                    ok = True
                    break
                mvs2[i] = mvs[i]
        if ok: break
