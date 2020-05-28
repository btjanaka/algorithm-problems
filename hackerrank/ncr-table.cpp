// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) ncr-table
// Title: nCr table
// Link: https://www.hackerrank.com/challenges/ncr-table/problem
// Idea: Build Pascal's triangle, then index into it properly to get the final
// results.
// Difficulty: medium
// Tags: math, combinatorics, pascals-triangle
#include <bits/stdc++.h>

using namespace std;

int nCr[1010][1010];

int main() {
  ios_base::sync_with_stdio(false);

  nCr[1][1] = 1;
  for (int n = 1; n <= 1000; ++n) {
    for (int r = 1; r <= 1000; ++r) {
      if (n == 1 && r == 1) continue;
      nCr[n][r] = (nCr[n - 1][r] + nCr[n][r - 1]) % 1000000000;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
      cout << nCr[n + 1 - i][i + 1] << (i == n ? '\n' : ' ');
    }
  }

  return 0;
}
