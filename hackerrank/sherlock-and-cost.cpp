// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) sherlock-and-cost
// Title: Sherlock and Cost
// Link: https://www.hackerrank.com/challenges/sherlock-and-cost/problem
// Idea: Each element can either be 1 or b[i]. Thus, the recurrence relation for
// finding the maximum value at index i and value k is:
// f(i, k) = max_(k_prev in {1, b[i - 1]}) f(i - 1, k_prev) + abs(k - k_prev)
// At the end, we take the maximum over the possible values of the last element.
// Difficulty: medium
// Tags: dynamic-programming
#include <bits/stdc++.h>

using namespace std;

// Dimensions:
// 1: i = current index in b
// 2: k = current value being investigated -- since this is only ever 1 or b[i],
//    this really could have been dimension 2 instead of 110
int dp[100100][110];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Base case: there is no value at 0.
    dp[0][1] = dp[0][b[0]] = 0;
    // Fill up rest of dp table.
    for (int i = 1; i < n; ++i) {
      for (int k : {1, b[i]}) {  // Abuse initializer lists :D
        dp[i][k] = max(dp[i - 1][1] + abs(k - 1),
                       dp[i - 1][b[i - 1]] + abs(k - b[i - 1]));
      }
    }

    // Calculate and output maximum.
    cout << max(dp[n - 1][1], dp[n - 1][b[n - 1]]) << endl;
  }

  return 0;
}
