// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) its-np-complete-wait-no-its
// Title: It's NP Complete! Wait no its...
// Link:
// https://www.hackerrank.com/contests/acmxfacebook-competition-2020/challenges/its-np-complete-wait-no-its-/problem
// Idea: It is easy to check if Karthik can buy everything. If he cannot, then
// greedily choose the least expensive items possible.
// Difficulty: easy
// Tags: greedy
#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; ++i) cin >> prices[i];
  sort(prices.begin(), prices.end());
  long long sum = 0;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    sum += prices[i];
    if (sum > m) {
      ok = false;
      cout << i << " The catalogue is wrong!\n";
      break;
    }
  }
  if (ok) cout << sum << endl;
  return 0;
}
