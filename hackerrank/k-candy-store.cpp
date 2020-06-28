// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) k-candy-store
// Title: K Candy Store
// Link: https://www.hackerrank.com/challenges/k-candy-store/problem
// Idea: We can see this as the problem of choosing n-1 places to put "dividers"
// in a sequence of k elements that split it into n separate sequences. There
// are n+k-1 places to put these dividers, so the answer is n+k-1 choose n-1.
// Difficulty: medium
// Tags: math, combinatorics
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int nCr[2020][2020];

int main() {
  // Construct Pascal's triangle for calculating combos.
  for (int n = 0; n < 2020; ++n) {
    for (int r = 0; r <= n; ++r) {
      if (r == 0 || r == n) {
        nCr[n][r] = 1;
      } else {
        nCr[n][r] = (nCr[n - 1][r] + nCr[n - 1][r - 1]) % MOD;
      }
    }
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, k;
    cin >> n >> k;
    cout << nCr[n + k - 1][n - 1] << '\n';
  }

  return 0;
}
