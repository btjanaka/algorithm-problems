# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) bomber-man
# Title: The Bomberman Game
# Link: https://www.hackerrank.com/challenges/bomber-man/problem
# Idea: It turns out that there is a pattern of x positions that repeats during
# Bomberman's game, so we just need to generate the first x positions and then
# figure out which position the board would be in at time n. As for finding x, I
# just kept trying higher powers of 2 to see which one worked; I found 64 works.
# Difficulty: medium
# Tags: implementation
from copy import deepcopy

rows, cols, n = map(int, input().split())
grid = []
for _ in range(rows):
    grid.append(
        list(map(lambda ch: -1 if ch == '.' else 1, list(input().strip()))))

seq = []
seq.append(deepcopy(grid))
for itr in range(63):  # First 64 positions.
    # Increment all bombs.
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] != -1:
                grid[r][c] += 1

    if itr % 2 == 0:
        # Add bombs.
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == -1: grid[r][c] = 0
    else:
        # Remove bombs.
        remove = set()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 3:
                    remove.add((r, c))
                    remove.add((r + 1, c))
                    remove.add((r - 1, c))
                    remove.add((r, c - 1))
                    remove.add((r, c + 1))
        for r, c in remove:
            if r < rows and r >= 0 and c < cols and c >= 0:
                grid[r][c] = -1

    seq.append(deepcopy(grid))


def print_ans(ans):
    """Prints the number representation of the answer out as characters."""
    for row in ans:
        print(''.join(map(lambda x: '.' if x == -1 else 'O', row)))


print_ans(seq[(n - 1) % len(seq)])
