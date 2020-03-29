// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) easy-sum
// Title: Easy Sum
// Link: https://www.hackerrank.com/challenges/easy-sum/problem
// Idea: The value (i % m) forms a repeating cycle of 1,2,...,m-1,0. We can
// count the number of times the whole cycle occurs fully -- this is n // m.
// We take this sum and add it to the sum of the remaining part of n that was
// not covered by a whole "cycle of m."
// Difficulty: medium
// Tags: math
#include <stdio.h>
typedef long long ll;

int main() {
  ll t, n, m;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    ll whole = n / m;
    ll rem = n % m;
    ll whole_sum = (m * (m - 1) / 2) * whole;  // Sum of arithmetic series
    ll rem_sum = rem * (rem + 1) / 2;
    printf("%lld\n", whole_sum + rem_sum);
  }
  return 0;
}
