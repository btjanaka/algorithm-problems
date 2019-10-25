# Author: btjanaka (Bryon Tjanaka)
# Problem: (LeetCode) 1201
# Title: Ugly Number III
# Link: https://leetcode.com/problems/ugly-number-iii/
# Idea: Binary search for numbers in the range [1, n * a * b * c] - we can
# calculate what uglieth number the current number is via inclusion-exclusion
# principle (see code comments for more details).
# Difficulty: medium
# Tags: gcd, math
import math


class Solution:

    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        lcm_ab = a * b // math.gcd(a, b)
        lcm_bc = b * c // math.gcd(b, c)
        lcm_ac = a * c // math.gcd(a, c)
        lcm_abc = lcm_ab * c // math.gcd(lcm_ab, c)

        # Calculate what uglieth number this number N is. We need to somehow
        # count the number of multiples of a, b, or c between 1 and N. The base
        # number is the number of multiples from a, b, or c:
        #   | N // a + N // b + N // c |
        # Then we subtract out the multiples that are shared by any pair of a,
        # b, and c - this corresponds to subtracting the multiples of lcm_ab,
        # lcm_bc, and lcm_ac, i.e.
        #  | - N // lcm_ab - N // lcm_bc - N // lcm_ac |
        # Finally, we add back the multiples of a, b, and c, i.e.
        #  | + N // lcm_abc |
        # This is perhaps better looked at as a Venn diagram, with the multiple
        # of a, b, and c:
        #          -----
        #          | a |
        #        ---   ---
        #        | b   c |
        #        ---------
        # We can see that a and b share some multiples, b and c share some, and a
        # and c share some. We use inclusion-exclusion principle to ensure we
        # count everything only once, as describe above.
        def what_ugly_num_is_this(N):
            return N // a + N // b + N // c - N // lcm_ab - N // lcm_bc - N // lcm_ac + N // lcm_abc

        lo = 1
        hi = n * a * b * c
        while lo < hi:
            mid = (lo + hi) // 2
            mid_n = what_ugly_num_is_this(mid)
            if mid_n < n:
                lo = mid
            elif mid_n > n:
                hi = mid
            else:
                return mid - min(mid % a, mid % b, mid % c)
