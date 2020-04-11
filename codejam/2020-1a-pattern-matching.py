# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2020-1a-pattern-matching
# Title: Pattern Matching
# Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
# Idea: We need to advance through each string until the last asterisk. When
# all we have left are strings with a single asterisk on the left, we check if
# the longest string ends with all the other strings (exclude the asterisk).
# Before we reach these endings, though, we iterate through the characters in
# one string at a time. Since the maximum allowed pattern length is 10000, but
# there are only 5000 characters at most (50 patterns of 100), we can afford to
# simply "eat up" one string at a time.
# Difficulty: medium
# Tags: greedy
for ca in range(1, int(input()) + 1):
    n = int(input())
    p = [None for _ in range(n)]
    for i in range(n):
        p[i] = input().strip()
        p[i] = p[i].split()
        # Remove redundant *'s
        p[i] = ''.join(p[i][j]
                       for j in range(len(p[i]))
                       if p[i][j].isalpha() or p[i][j - 1] != '*')

    last_star = [p[i].rindex('*') for i in range(n)]

    res = []
    ptr = [0 for _ in range(n)]
    ok = True
    while True:

        if all(ptr[i] == last_star[i] for i in range(n)):
            # Ending -- check if all the endings are substring of longest
            # ending.
            endings = [p[i][last_star[i] + 1:] for i in range(n)]
            maxlen = max(len(e) for e in endings)
            max_ending = None
            for e in endings:
                if len(e) == maxlen:
                    max_ending = e
                    break
            for e in endings:
                ok = ok and max_ending.endswith(e)
            if ok:
                res.append(max_ending)
            break

        starts = set(p[i][ptr[i]] for i in range(n)) - set(['*'])
        if len(starts) > 1:
            # Start with more than one letter
            ok = False
            break

        if all(p[i][ptr[i]] == '*' for i in range(n)):
            for i in range(n):
                if ptr[i] != last_star[i]:
                    ptr[i] += 1
                    while p[i][ptr[i]] != '*':
                        res.append(p[i][ptr[i]])
                        ptr[i] += 1
                    break
        else:
            # Letter
            for i in range(n):
                if p[i][ptr[i]] != '*':
                    for j in range(n):
                        if p[j][ptr[j]] == p[i][ptr[i]] and i != j:
                            ptr[j] += 1
                    res.append(p[i][ptr[i]])
                    ptr[i] += 1
                    break

    print("Case #{}: {}".format(ca, ''.join(res) if ok else '*'))
