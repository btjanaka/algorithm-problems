# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) aliennumbers
# Title: Alien Numbers
# Link: https://open.kattis.com/problems/aliennumbers
# Idea: Implement change of base for numbers.
# Difficulty: easy
# Tags: implementation, math
n = int(input())
for ca in range(1, n + 1):
    code, src, tgt = input().strip().split()
    src_b = len(src)
    tgt_b = len(tgt)

    # Convert to base 10
    src = list(src)
    code = [src.index(ch) for ch in code[::-1]]
    base_10 = 0
    pow_base = 1
    for d in code:
        base_10 += pow_base * d
        pow_base *= src_b

    # Convert to the base of the target
    num = []
    while base_10 != 0:
        num.append(base_10 % tgt_b)
        base_10 //= tgt_b
    if len(num) == 0: num.append(0)
    num = num[::-1]

    print(f"Case #{ca}: {''.join(tgt[x] for x in num)}")
