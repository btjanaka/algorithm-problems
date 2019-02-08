# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 11729
class sol:

    def __init__(self, b, j):
        self.b = b
        self.j = j

    def __lt__(self, rhs):
        self_first = self.b + max(self.j, rhs.b + rhs.j)
        rhs_first = rhs.b + max(rhs.j, self.b + self.j)
        return self_first < rhs_first

    def __str__(self):
        return f"j: {j}, b: {b}"


n = int(input())
case = 0
while n != 0:
    case += 1
    soldiers = []
    for i in range(n):
        b, j = map(int, input().strip().split())
        soldiers.append(sol(b, j))

    soldiers.sort()

    tot = 0
    end = 0
    for i in range(n):
        tot += soldiers[i].b
        end = max(end, tot + soldiers[i].j)
    print(f"Case {case}: {end}")

    # next input
    n = int(input())
