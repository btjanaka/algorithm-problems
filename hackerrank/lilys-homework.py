# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) lilys-homework
# Title: Lily's Homework
# Link: https://www.hackerrank.com/challenges/lilys-homework/problem
# Idea: The solution array must be sorted either ascending or descending, so
# sort and count the number of swaps.
# Difficulty: medium
# Tags: graph, sort, cycle, count-swaps
def count_swaps(a, b):
    """Counts swaps to make a equal to b

    See https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
    for reference.
    """
    # Find the position of every number in b.
    # Keep in mind that the integers are distinct.
    b_pos = {}
    for i in range(n):
        b_pos[b[i]] = i

    # A "graph" - maps the positions in a to the final positions in b
    g = [b_pos[a[i]] for i in range(n)]
    visited = [False for _ in range(n)]

    # Find cycles and calculate their length - number of swaps
    # required for each cycle is (cycle length) - 1
    swaps = 0
    for i in range(n):
        if visited[i]: continue
        cur = g[i]
        links = 1
        while cur != i:
            visited[cur] = True
            cur = g[cur]  # Advance in the cycle
            links += 1
        swaps += links - 1
    return swaps


n = int(input())
arr = list(map(int, input().split()))
print(
    min(count_swaps(arr, sorted(arr)),
        count_swaps(arr, sorted(arr, reverse=True))))
