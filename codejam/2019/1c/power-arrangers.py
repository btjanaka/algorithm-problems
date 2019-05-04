# Author: btjanaka (Bryon Tjanaka)
# Problem: (Google Code Jam) Power Arrangers

import sys
from collections import defaultdict

# Main idea:
# - if we look at all the first letters we know what first letter is lacking, and
#   we can then determine the first letter of the missing permutation
# - then from the one with that first letter, we can look for the second letter,
#   and then third
# - fourth is a bit of a special case since you only need 1 piece of info then
#
# Query count: 119 for A1, 23 for A2, 5 for A3, 1 for A4 - 148 total


def query(k):
    print(k)
    sys.stdout.flush()
    return input().strip()


t, f = map(int, input().split())
for ca in range(t):
    perms = ["" for _ in range(119)]
    ans = ""
    used = {'A', 'B', 'C', 'D', 'E'}

    # progressively narrow down remaining letters
    for j in range(1, 5):
        letters = defaultdict(int)
        for i in range(119):
            if perms[i] == ans:
                q = query(5 * i + j)
                perms[i] += q
                letters[q] += 1
        a = min(letters, key=lambda x: letters[x])
        used.remove(a)
        if j == 4: ans += list(used)[0]
        ans += a

    print(ans)
    sys.stdout.flush()

    if input() == 'N': break
