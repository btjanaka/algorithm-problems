# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) gamedesign
# Title: Game Design
# Link: https://open.kattis.com/problems/gamedesign
# Idea: To avoid ever having the ball hit another block inadvertently, maintain
# several bounds telling how large the grid is so far. Then add a block for each
# move, and make sure the new block is outside the grid. The game is impossible
# if it ends in LRL, RLR, UDU, or DUD because that would require making the ball
# pass over the hole and then back.
# Difficulty: medium
# Tags: implementation, geometry
import sys
X, Y = 0, 1

for line in sys.stdin:
    moves = line.strip()
    if line == "": break

    bad = False
    for end in ["LRL", "RLR", "UDU", "DUD"]:
        if moves.endswith(end):
            bad = True
            break
    if bad:
        print("impossible")
        continue

    ball_coords = [0, 0]
    positions = []

    # Current grid bounds
    bottom = -1
    top = 1
    left = -1
    right = 1

    def opposite(c):
        return {'R': 'L', 'L': 'R', 'U': 'D', 'D': 'U'}[c]

    coord_history = [ball_coords[::]]
    for i in range(len(moves)):
        # print(left, right, bottom, top)
        add = None
        m = moves[i]

        if i >= 2 and m == moves[i - 2] and moves[i - 1] == opposite(m):
            ball_coords = coord_history[-2]
            coord_history.append(ball_coords[::])
            continue

        if m == 'L':
            add = [left - 1, ball_coords[Y]]
            ball_coords[X] = left
            left -= 2
        elif m == 'R':
            add = [right + 1, ball_coords[Y]]
            ball_coords[X] = right
            right += 2
        elif m == 'U':
            add = [ball_coords[X], top + 1]
            ball_coords[Y] = top
            top += 2
        elif m == 'D':
            add = [ball_coords[X], bottom - 1]
            ball_coords[Y] = bottom
            bottom -= 2

        coord_history.append(ball_coords[::])
        positions.append(add)

    def pxy(p):
        print(f"{p[X]} {p[Y]}")

    transform = [-ball_coords[X], -ball_coords[Y]]
    last = moves[-1]
    pxy(transform)
    positions.pop()
    print(len(positions))
    for pos in positions:
        pxy([pos[X] + transform[X], pos[Y] + transform[Y]])
