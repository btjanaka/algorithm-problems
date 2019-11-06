# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) remainderreminder
# Title: Remainder Reminder
# Link: https://open.kattis.com/problems/remainderreminder
# Idea: Start by finding the three largest box sizes possible. Then, we will
# have three numbers m1, m2, m3, and the remaining books a1, a2, and a3 when
# filling those boxes. This is an almost perfect setup for the Chinese remainder
# theorem, as we have a number that, when divided by three numbers, gives three
# remainders. The caveat is that the three divisors are not pairwise coprime as
# CRT requires. We still use a sieve for searching for the number, but we modify
# it by incrementing by LCM(m1,m2) instead of m1m2. See
# (https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Search_by_sieving)
# for more info on the sieve.
# Difficulty: medium
# Tags: math
import sys
from math import ceil, gcd

for line in sys.stdin:
    a, b, c, d, e, f, g = map(int, line.split())

    # Find 3 largest volumes
    volumes = sorted(
        (i * (a - 2 * i) * (b - 2 * i) for i in range(1, a // 2 + 1)),
        reverse=True)[:3]

    # Note that since the volumes are not necessarily co-prime, we have to add
    # the LCM of m1 and m2 in the second step of the sieve.
    m1, m2, m3 = volumes
    a1, a2, a3 = c, d, e

    books = a1 + m1 * ceil((f - a1) / m1)
    while books % m2 != a2:
        books += m1
    lcm12 = m1 * m2 // gcd(m1, m2)
    while books % m3 != a3:
        books += lcm12
    print(books)
