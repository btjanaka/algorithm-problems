// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) 2d-array
// Title: 2D Array
// Link: https://www.hackerrank.com/challenges/2d-array/problem
// Idea: Brute force.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
using namespace std;

int main() {
  int g[6][6];
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) cin >> g[i][j];

  int mx = INT_MIN;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int sum = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i + 1][j + 1] +
                g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];
      mx = max(mx, sum);
    }
  }

  cout << mx << endl;
  return 0;
}
