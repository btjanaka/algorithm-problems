// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) number-list
// Title: Number List
// Link: https://www.hackerrank.com/challenges/number-list/problem
// Idea: It is much easier to count the number of lists with maxima <= k. This
// can be done by finding all contiguous sequences of items <= k. Say one such
// sequence has length l; then it will create l(l+1)/2 lists with maxima <= k.
// Thus, we count up the total number of "bad" lists and subtract from the total
// number of lists, which is n(n+1)/2 (i.e. n lists of len 1, n-1 lists of len
// 2, ...).
// Difficulty: medium
// Tags: math, combinatorics
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Counts the number of contiguous sublists in a list of length n.
ll count_lists(ll n) { return n * (n + 1) / 2; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    ll bad_lists = 0;  // Number of lists with max <= k.
    ll num_bad = 0;    // Current count of items <= k.
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x > k) {
        bad_lists += count_lists(num_bad);  // Add lists with max <= k.
        num_bad = 0;
      } else {
        ++num_bad;
      }
    }
    bad_lists += count_lists(num_bad);  // Grab stragglers.

    cout << count_lists(n) - bad_lists << '\n';
  }
  return 0;
}
