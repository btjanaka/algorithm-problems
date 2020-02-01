// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) larrys-array
// Title: Larry's Array
// Link: https://www.hackerrank.com/challenges/larrys-array/problem
// Idea: Same as in Kattis Bread Sorting, the problem can be solved only if the
// number of swaps required to sort the array is even. This is because the
// operation given corresponds to doing two swaps at a time.
// Difficulty: medium
// Tags: sorting, graph
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // Input.
    vector<int> original(n);
    for (int i = 0; i < n; ++i) cin >> original[i];

    // Count swaps. See
    // https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
    // for background.
    int swaps = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;

      // Follow the cycle.
      visited[i] = true;
      int cur_num = original[i];
      while (true) {
        int actual_idx = cur_num - 1;
        visited[actual_idx] = true;
        if (actual_idx == i) break;
        cur_num = original[actual_idx];
        ++swaps;
      }
    }

    // Output.
    cout << (swaps % 2 == 0 ? "YES" : "NO") << "\n";
  }

  return 0;
}
