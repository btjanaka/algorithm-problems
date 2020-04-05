import sys

def is_square(n):
    lo = 0; hi = int("9" * 500)
    while hi != lo:
        mid = (lo + hi) // 2
        sq = mid * mid
        if sq == n:
            return True
        elif sq > n:
            hi = mid
        else:
            lo = mid + 1
    return False

def is_int(n):
    lo = 0; hi = int("9" * 500)
    while hi != lo:
        mid = (lo + hi) // 2
        res = mid * n[1]
        if res == n[0]:
            return (True, mid)
        elif res > n[0]:
            hi = mid
        else:
            lo = mid + 1
    return (False, -1)

for line in sys.stdin:
    num1, num2 = line.split()
    num1_tok = num1.split("/")
    num2_tok = num2.split("/")

    a, b = [1,1], [1,1]

    a[0] = int(num1_tok[0])
    if len(num1_tok) == 2:
        a[1] = int(num1_tok[1])

    b[0] = int(num2_tok[0])
    if len(num2_tok) == 2:
        b[1] = int(num2_tok[1])

    a_sq = (a[0]*a[0], a[1]*a[1])
    b_sq = (b[0]*b[0], b[1]*b[1])
    c_sq = (a_sq[0]*b_sq[1] + a_sq[1]*b_sq[0], a_sq[1]*b_sq[1])
    ab_2 = (a[0] * b[0], a[1] * b[1] * 2)

    if is_square(c_sq[0]) and is_square(c_sq[1]):
        res = is_int(ab_2)
        if res[0]:
            print(res[1])
        else:
            print("no")
    else:
        print("no")
