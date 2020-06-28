// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) coinage
// Title: Coinage
// Link: https://www.hackerrank.com/challenges/coinage/problem
// Idea: Brute force search over all possible amounts of each domination. The
// last dimension (the 1's) can be calculated instead of searched, so the search
// is only O(1000^3), which C++ handles.
// Difficulty: medium
// Tags: math, complete-search
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> c >> d;
    int tot = 0, sum = 0;
    for (int i = 0; i <= d; ++i) {
      sum = i * 10;
      if (sum > n) break;

      for (int j = 0; j <= c; ++j) {
        sum = i * 10 + j * 5;
        if (sum > n) break;

        for (int k = 0; k <= b; ++k) {
          sum = i * 10 + j * 5 + k * 2;
          if (sum > n) break;
          if (n - sum <= a) ++tot;  // If the ones are okay, add to the answer.
        }
      }
    }

    cout << tot << '\n';
  }
  return 0;
}
