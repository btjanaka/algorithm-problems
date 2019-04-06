# Author: btjanaka (Bryon Tjanaka)
# Problem: (Google Code Jam) Foregone Solution
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
