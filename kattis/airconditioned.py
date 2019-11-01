# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) airconditioned
# Title: Air Conditioned Minions
# Link: https://open.kattis.com/problems/airconditioned
# Idea: Pick a room for the minion who has the lowest upper bound temperature
# and find all minions who can fit into that room. Then repeat for the remaining
# minions, until there are no minions left.
# Difficulty: medium
# Tags: greedy

# Input
n = int(input())
minions = []
for _ in range(n):
    minions.append(tuple(map(int, input().split())))

# Calculation
rooms = 0
num_done = 0
done = [False for _ in range(n)]
while num_done < n:
    rooms += 1

    # Find the minion with lowest upper bound
    room_tmp = 2 * n
    for i in range(n):
        if done[i]: continue
        room_tmp = min(minions[i][1], room_tmp)

    # Eliminate minions in this room
    for i in range(n):
        if not done[i] and minions[i][0] <= room_tmp <= minions[i][1]:
            num_done += 1
            done[i] = True

print(rooms)
