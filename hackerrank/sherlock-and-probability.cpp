// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) sherlock-and-probability
// Title: Sherlock and Probability
// Link: https://www.hackerrank.com/challenges/sherlock-and-probability/problem
// Idea: First count the number of pairs n^2 (since order of i and j matters).
// Then count the number of pairs of 1's by maintaining a sliding window of
// length k and keeping track of the number of 1's in the window. Each time a 1
// is at the left end of the window, we count the number of pairs it makes with
// the rest of the 1's. Finally, we have to remember to reduce the fraction
// using the gcd.
// Difficulty: medium
// Tags: arrays, probability
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll tot = n * n;
    string s;
    cin >> s;
    ll pairs = 0;

    // 1 for each identical pair.
    for (int i = 0; i < n; ++i) pairs += s[i] == '1';

    // Sliding window of length k.
    int start = 0, end = 0, num_ones = 0;

    // Count the ones in the first k items.
    for (; end < n - 1 && end - start < k; ++end) {
      num_ones += s[end] == '1';
    }
    num_ones += s[end] == '1';

    // Move the window along the array.
    for (int i = 0; i < n - k - 1; ++i) {
      if (s[start] == '1') {
        // Add on 2 pairs for each of the 1's within range of the starting 1.
        pairs += (num_ones - 1) * 2;
        --num_ones;  // Remove this 1 because we are advancing forward.
      }
      ++start;
      ++end;
      if (s[end] == '1') {
        ++num_ones;
      }
    }
    // Cover the end.
    for (; start < end; ++start) {
      if (s[start] == '1') {
        pairs += (num_ones - 1) * 2;
        --num_ones;
      }
    }

    // Output.
    if (pairs == 0)
      cout << "0/1\n";
    else {
      int g = gcd(tot, pairs);
      cout << (pairs / g) << '/' << (tot / g) << '\n';
    }
  }

  return 0;
}
