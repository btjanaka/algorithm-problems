// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) closest-numbers
// Title: Closest Numbers
// Link: https://www.hackerrank.com/challenges/closest-numbers/problem
// Idea: Sort, then check all differences.
// Difficulty: easy
// Tags: array, list, sort
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> nums;
  int n;
  cin >> n;
  nums.reserve(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  sort(nums.begin(), nums.end());

  int min_diff = INT_MAX;
  for (int i = 1; i < n; ++i) {
    if (nums[i] - nums[i - 1] < min_diff) {
      min_diff = nums[i] - nums[i - 1];
    }
  }

  bool first = true;
  for (int i = 1; i < n; ++i) {
    if (nums[i] - nums[i - 1] == min_diff) {
      if (first) {
        first = false;
      } else {
        cout << ' ';
      }
      cout << nums[i - 1] << ' ' << nums[i];
    }
  }
  cout << '\n';

  return 0;
}
