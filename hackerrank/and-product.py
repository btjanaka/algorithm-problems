# Author: btjanaka (Bryon Tjanaka)
# Problem: (HackerRank) and-product
# Title: AND Product
# Link: https://www.hackerrank.com/challenges/and-product/problem
# Idea: The problem boils down to finding the leftmost non-aligned bit between
# two numbers, i.e. the leftmost bit that is not identical in a and b. We know
# that the bits to the left of this non-aligned bit will be preserved, as they
# are maintained in every number from a to b. However, the bit starting with
# this non-aligned bit will be removed because at some point in the range from a
# to b, these bits will change from 0 to 1. Thus, we just need to find all the
# aligned bits and return the result.
# Difficulty: medium
# Tags: bit-manipulation

# Great printout of a table - didn't want to remove it :)
#  for i in range(32):
#      print(f"{i:2} |", end="")
#      for j in range(32):
#          if j < i:
#              tot = "_"
#          else:
#              tot = i
#              for k in range(i + 1, j + 1):
#                  tot &= k
#          print(f" {tot:>2}", end="")
#      print()

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())

    # Find first position where the bits are not aligned - i.e. where they are
    # not the same.
    nonaligned_pos = -1
    for pos in range(32, -1, -1):
        a_bit = a & (1 << pos)
        b_bit = b & (1 << pos)
        if a_bit != b_bit:
            nonaligned_pos = pos
            break

    # Numbers are the same!
    if nonaligned_pos == -1:
        print(a)
        continue

    # Example: If we want to remove the bits starting at nonaligned_pos 1, we
    # need a bitset 11100.
    # We obtain such a bitset for removing the nonaligned bits by getting 00100,
    # subtracting 1 to get 00011, and performing bitwise NOT to get 11100.
    nonaligned_remover = ~((1 << (nonaligned_pos + 1)) - 1)
    print(nonaligned_remover & a)
