// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) unbounded-knapsack
// Title: Knapsack
// Link: https://www.hackerrank.com/challenges/unbounded-knapsack/problem
// Idea: Classic DP algorithm.
// Difficulty: medium
// Tags: dynamic-programming
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &(x));

using namespace std;

bool dp[2200];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, k;
    GET(n);
    GET(k);
    unordered_set<int> coins;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      coins.insert(x);
    }

    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i <= k; ++i) {
      if (!dp[i]) continue;
      for (int c : coins) {
        int next = i + c;
        dp[next] = true;
      }
    }

    int res = 0;
    for (res = k; res >= 0 && !dp[res]; --res) {
    }
    printf("%d\n", res);
  }
  return 0;
}
