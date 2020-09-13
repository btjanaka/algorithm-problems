// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) leonardo-and-prime
// Title: Leonardo's Prime Factors
// Link: https://www.hackerrank.com/challenges/leonardo-and-prime/problem
// Idea: Find the first few primes and take their cumulative product. Then take
// in each query and binary search for the location of the number in the
// cumulative product list. The location in the list tells us how many
// factors the number has. We only need to take cumulative product (instead of
// multiplying all possible combos, e.g. 2 * 5 instead of 2 * 3 * 5, because we
// know that the smallest number with k prime factors will be product of the
// first k primes -- e.g. in that cast, 2 * 3 is already smaller than 2 * 5).
// Difficulty: medium
// Tags: math, primes
#include <bits/stdc++.h>
using namespace std;

const long long prime_limit = 50;  // Limit to search for primes.

int main() {
  // Run eratosthenes to find primes.
  vector<long long> prime_product;  // Cumulative product of the primes.
  vector<bool> isprime(prime_limit, true);
  isprime[0] = false;
  isprime[1] = false;
  for (long long i = 0; i < prime_limit; ++i) {
    if (isprime[i]) {
      prime_product.push_back(
          prime_product.size() == 0 ? i : prime_product.back() * i);
      for (int j = i * 2; j < prime_limit; j += i) {
        isprime[j] = false;
      }
    }
  }

  // Input the numbers and search for their position in the array.
  int q;
  long long n;
  cin >> q;
  while (q--) {
    cin >> n;
    int factors = upper_bound(prime_product.begin(), prime_product.end(), n) -
                  prime_product.begin();
    cout << factors << '\n';
  }

  return 0;
}
