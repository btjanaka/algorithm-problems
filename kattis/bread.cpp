// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) bread
// Title: Bread Sorting
// Link: https://open.kattis.com/problems/bread
// Idea: Count the number of swaps required to sort the array. If this number is
// even, we are good to go. This works because each operation corresponds to 2
// swaps, so we in essence do 2 swaps at a time when re-arranging the array.
// Difficulty: medium
// Tags: sorting, graph

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  while (cin >> n) {
    // Input.
    vector<int> original(n);
    unordered_map<int, int> actual;
    for (int i = 0; i < n; ++i) cin >> original[i];
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      actual[x] = i;
    }

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
        int idx_in_actual = actual[cur_num];
        visited[idx_in_actual] = true;
        if (idx_in_actual == i) break;
        cur_num = original[idx_in_actual];
        ++swaps;
      }
    }

    // Output.
    cout << (swaps % 2 == 0 ? "Possible" : "Impossible") << "\n";
  }

  return 0;
}
