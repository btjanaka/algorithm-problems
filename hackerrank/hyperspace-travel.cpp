// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) hyperspace-travel
// Title: Hyperspace Travel
// Link: https://www.hackerrank.com/challenges/hyperspace-travel/problem
// Idea: Take the median of each dimension -- when n is even, take the lower of
// the two middle values rather than averaging them.
// Difficulty: medium
// Tags: geometry
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // Input the values for each dimension.
  vector<vector<int>> dims(m);
  int x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> x;
      dims[j].push_back(x);
    }
  }

  // Sort each dimension and output the median of each dimension.
  for (int i = 0; i < m; ++i) sort(dims[i].begin(), dims[i].end());

  for (int i = 0; i < m; ++i) {
    int median = n % 2 == 1 ? dims[i][n / 2] : dims[i][n / 2 - 1];
    cout << median << (i == m - 1 ? '\n' : ' ');
  }

  return 0;
}
