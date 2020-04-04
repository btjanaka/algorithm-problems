# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2020-qual-esab-atad
# Title: ESAb ATAd
# Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
# Idea: First think of the array as consisting of "symmetric pairs", pairs of
# entries that are equidistant from the center of the array. We can detect which
# change happened if we are able to find a "same pair", where both entries in
# the pair have the same value, and a "different pair", where both entries in
# the pair have a different value. When a "same pair" changes value (we detect
# this by querying one of the entries), it can be the result of either a
# reverse+complement, or just a complement (just reversing does nothing since
# the entries are the same). When a "different pair" changes value, it can be
# the result of either a reverse or a complement. Thus, to solve this problem,
# we split our queries into cycles of 10. At the beginning of the cycle, we
# query the same and different pair we have found (if we have found them) to see
# if they have changed -- if they have, we can figure out what change happened
# and apply it to a running state of our array. We spend the rest of our queries
# finding the values of the pairs themselves.
# Difficulty: medium
# Tags: interactive, ad-hoc
import sys


def get_pos(i):
    print(i + 1)
    sys.stdout.flush()
    return int(input())


def complement(a):
    return [1 - x if x is not None else None for x in a]


def reverse(a):
    return a[::-1]


t, b = map(int, input().split())
for _ in range(t):
    res = [None] * b
    pairs = [[i, b - i - 1] for i in range(b // 2)]
    # Can check if these changed just by querying one of them
    same_pair, diff_pair = None, None
    for cycle in range(15):  # 15 cycles of 10
        queries = 10

        # Check for changes.
        same_pair_changed, diff_pair_changed = False, False
        if same_pair is not None:
            same_pair_changed = get_pos(same_pair[0]) != res[same_pair[0]]
            queries -= 1
        if diff_pair is not None:
            diff_pair_changed = get_pos(diff_pair[0]) != res[diff_pair[0]]
            queries -= 1

        # Apply changes based on data.
        if same_pair_changed and (diff_pair_changed is None):
            res = complement(res)
        elif diff_pair_changed and (same_pair_changed is None):
            res = reverse(res)
        elif same_pair_changed and diff_pair_changed:
            res = complement(res)
        elif same_pair_changed and not diff_pair_changed:
            res = reverse(complement(res))
        elif not same_pair_changed and diff_pair_changed:
            res = reverse(res)
        elif not same_pair_changed and not diff_pair_changed:
            pass  # Nothing happened!

        # Fill out pair positions.
        while queries >= 2:
            if len(pairs) == 0: break
            x, y = pairs.pop()
            res[x] = get_pos(x)
            res[y] = get_pos(y)
            if (same_pair is None) and res[x] == res[y]:
                same_pair = [x, y]
            if (diff_pair is None) and res[x] != res[y]:
                diff_pair = [x, y]
            queries -= 2

        if len(pairs) == 0: break  # We found all pairs.

        # Throw away remaining queries.
        while queries > 0:
            get_pos(0)
            queries -= 1

    print(''.join(str(x) for x in res))
    if input().strip() == "N":
        sys.exit()
