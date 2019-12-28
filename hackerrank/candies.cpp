// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) candies
// Title: Candies
// Link: https://www.hackerrank.com/challenges/candies/problem
// Idea: We can easily find all the places where a 1 is necessary -- these are
// essentially the "local minima." Then we can fill in between these places by
// essentially climbing a hill of values.
// Difficulty: Medium
// Tags: arrays, greedy
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> ratings(n), candies(n), ones;
  for (int i = 0; i < n; ++i) cin >> ratings[i];

  // Find all "local minima"
  for (int i = 0; i < n; ++i) {
    if ((i == 0 || ratings[i] <= ratings[i - 1]) &&
        (i == n - 1 || ratings[i] <= ratings[i + 1])) {
      candies[i] = 1;
      ones.push_back(i);
    }
  }

  // Handle everything at each end. The ends are guaranteed to be strictly
  // increasing.
  for (int i = ones[0] - 1; i >= 0; --i) candies[i] = candies[i + 1] + 1;
  for (int i = ones.back() + 1; i < n; ++i) candies[i] = candies[i - 1] + 1;

  // Handle everything in between the ones.
  for (int i_ones = 1; i_ones < ones.size(); ++i_ones) {
    int left = ones[i_ones - 1], right = ones[i_ones];
    if (left == right - 1) continue;  // Nothing in between.
    while (left < right) {
      // Use a maximum to account for the edge case at the end -- when left
      // and right meet, they may need to set candies[i] higher. The last two
      // cases are an edge case where there is a sort of "plateau" on one side,
      // so left and right get stuck.
      if (ratings[left + 1] > ratings[left]) {
        candies[left + 1] = max(candies[left + 1], candies[left] + 1);
        ++left;
      } else if (ratings[right - 1] > ratings[right]) {
        candies[right - 1] = max(candies[right - 1], candies[right] + 1);
        --right;
      } else if (ratings[left + 1] == ratings[left]) {
        candies[left + 1] = max(1, candies[left + 1]);
        ++left;
      } else if (ratings[right - 1] == ratings[right]) {
        candies[right - 1] = max(1, candies[right - 1]);
        --right;
      }
    }
  }

  // for (int i = 0; i < n; ++i) cout << candies[i] << endl;

  cout << accumulate(candies.begin(), candies.end(), 0ll) << endl;

  return 0;
}
