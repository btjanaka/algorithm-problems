# Author: btjanaka (Bryon Tjanaka)
# Problem: (Kattis) circuitmath
# Title: Circuit Math
# Link: https://open.kattis.com/problems/circuitmath
# Idea: Use a stack to keep track of operators, just like in an RPN calculator.
# Difficulty: easy
# Tags: stack, rpn

n = int(input())

# Map between characters and Boolean value.
d = {}
vals = input().strip().split()
for i in range(n):
    d[chr(ord('A') + i)] = vals[i] == 'T'

# Go through the commands and operate as necessary.
cmds = input().strip().split()
s = []  # Stack
for c in cmds:
    if c.isupper():
        # Push letters to the stack
        s.append(d[c])
    elif c == '*':
        # For AND, pop the first two numbers and push their AND
        a, b = s[-1], s[-2]
        s.pop()
        s.pop()
        s.append(a and b)
    elif c == '+':
        # For OR, pop the first two numbers and push their OR
        a, b = s[-1], s[-2]
        s.pop()
        s.pop()
        s.append(a or b)
    elif c == '-':
        # For NOT, replace the first number with its NOT
        s[-1] = not s[-1]

# Booleans evaluate to an index - False is 0, True is 1
print(['F', 'T'][s[0]])
