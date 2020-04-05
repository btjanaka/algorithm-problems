# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2019-qual-foregone-solution
# Title: Foregone Solution
# Link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231
# Idea: Split every 4 into two 2's in the resulting numbers.
# Difficulty: easy
# Tags: math
ca = int(input().strip())

for caa in range(ca):
    n = int(input().strip())

    s = str(n)
    a = []
    b = []
    for i in range(len(s)):
        if s[i] == '4':
            a.append('2')
            b.append('2')
        else:
            a.append(s[i])
            b.append('0')

    a = int(''.join(a))
    b = int(''.join(b))
    print("Case #{}: {} {}".format(caa + 1, a, b))
