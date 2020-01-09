// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) greedy-florist
// Title: Greedy Florist
// Link: https://www.hackerrank.com/challenges/greedy-florist/problem
// Idea: Sort the numbers by descending order and assign them one by one to each
// friend. This ensures that the worst multipliers are given to the lowest
// prices.
// Difficulty: easy
// Tags: greedy
#include <bits/stdc++.h>
using namespace std;

int main() {
  // Input
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  // Sort to get an order that will lead to least cost.
  sort(c.begin(), c.end(), greater<int>());
  vector<int> prices(k);
  vector<int> count(k);
  for (int i = 0; i < n; ++i) {
    // Calculate cost of the item each friend handles
    // every k'th item starting from i % k.
    prices[i % k] += (++count[i % k]) * c[i];
  }
  cout << accumulate(prices.begin(), prices.end(), 0) << endl;

  return 0;
}
