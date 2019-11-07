// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) minimum-loss
// Title: Minimum Loss
// Link: https://www.hackerrank.com/challenges/minimum-loss/problem
// Idea: As we go through the array, use an ordered set to keep track of numbers
// we have seen so far. We can then search in this set in O(log n) time for the
// first number that is >= to the current one and then compute the loss. Note
// that one implementation of the ordered set is the C++ set.
// Difficulty: medium
// Tags: binary-search
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  set<ll> nums;
  ll minLoss = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    auto itr = nums.lower_bound(x);
    if (itr != nums.end()) {
      minLoss = min(minLoss, *itr - x);
    }
    nums.insert(x);
  }

  cout << minLoss << endl;

  return 0;
}
