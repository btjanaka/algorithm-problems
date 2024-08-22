// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 204
// Title: Count Primes
// Link: https://leetcode.com/problems/count-primes/
// Idea: Use Sieve of Eratosthenes to count number of primes less than n.
// Difficulty: Medium
// Tags:
class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> prime(n, true);

    int count = 0;

    for (int i = 2; i < n; ++i) {
      if (prime[i]) {
        ++count;
        for (int j = 2 * i; j < n; j += i) {
          prime[j] = false;
        }
      }
    }

    return count;
  }
};
