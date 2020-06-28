// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) identify-smith-numbers
// Title: Identify Smith Numbers
// Link: https://www.hackerrank.com/challenges/identify-smith-numbers/problem
// Idea: Factor the number and check the sum of the factors' digits and the
// number's digits.
// Difficulty: easy
// Tags: math
#include <bits/stdc++.h>

using namespace std;

int calc_digit_sum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  int n2 = n;

  int digit_sum = calc_digit_sum(n);
  int factor_sum = 0;
  while (n2 % 2 == 0) {
    n2 /= 2;
    factor_sum += 2;
  }
  // Can limit to n/2 because the larger factor would be the number itself,
  // which means the number is prime.
  for (int i = 3; i <= n / 2; i += 2) {
    while (n2 % i == 0) {
      n2 /= i;
      factor_sum += calc_digit_sum(i);
    }
  }

  cout << (digit_sum == factor_sum) << endl;

  return 0;
}
