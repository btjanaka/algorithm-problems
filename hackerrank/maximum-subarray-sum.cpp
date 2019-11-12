// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) maximum-subarray-sum
// Title: Maximum Subarray Sum
// Link: https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
// Idea: See
// https://www.quora.com/What-is-the-logic-used-in-the-HackerRank-Maximise-Sum-problem.
// The O(n^2) brute force solution is fairly straightforward; we can optimize it
// by looking only for the smallest previous sum that is greater than the
// current sum as we iterate through the array.
// Difficulty: hard
// Tags: dp, arrays
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int n;
    ll m;
    cin >> n >> m;
    set<ll> prefix;
    ll cur_sum = 0, max_sum = 0;
    for (int i = 0; i < n; ++i) {
      ll a;
      cin >> a;
      cur_sum = (cur_sum + a) % m;

      // The sum, modulo m, is maximized when we find the smallest prefix
      // greater than cur_sum.
      auto itr = prefix.upper_bound(cur_sum);
      if (itr != prefix.end())
        max_sum = max(max_sum, cur_sum - *itr + m);
      else
        // If nothing was found, we try this current sum.
        max_sum = max(cur_sum, max_sum);

      prefix.insert(cur_sum);
    }
    cout << max_sum << '\n';
  }
  return 0;
}
