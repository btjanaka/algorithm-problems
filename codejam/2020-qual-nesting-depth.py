# Author: btjanaka (Bryon Tjanaka)
# Problem: (CodeJam) 2020-qual-nesting-depth
# Title: Nesting Depth
# Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
# Idea: Similar to the classic balanced parentheses problem, except that we
# now keep track of an additional number telling the current depth. If the depth
# is too small for the next digit we encounter, we add on open parens, and if
# if it is too large, we add on closing parens.
# Difficulty: medium
# Tags: stack, greedy
for case in range(int(input())):
    s = input().strip()
    s2 = ""
    cur_depth = 0
    for ch in s:
        x = int(ch)
        if cur_depth < x:
            while cur_depth < x:
                s2 += "("
                cur_depth += 1
        elif cur_depth > x:
            while cur_depth > x:
                s2 += ")"
                cur_depth -= 1
        s2 += ch
    while cur_depth > 0:
        s2 += ")"
        cur_depth -= 1
    print("Case #{}: {}".format(case + 1, s2))
