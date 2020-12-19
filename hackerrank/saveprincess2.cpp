// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) saveprincess2
// Title: Bot saves princess
// Link: https://www.hackerrank.com/challenges/saveprincess2
// Idea: Find the location of the princess, then print out a move that brings us
// close.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, r, c;
  cin >> n >> r >> c;
  string buf;
  int pr, pc;
  for (int i = 0; i < n; ++i) {
    cin >> buf;
    for (int j = 0; j < n; ++j) {
      if (buf[j] == 'p') {
        pr = i;
        pc = j;
        goto found_princess;
      }
    }
  }
found_princess:
  if (r < pr) {
    cout << "DOWN\n";
  } else if (r > pr) {
    cout << "UP\n";
  } else if (c < pc) {
    cout << "RIGHT\n";
  } else if (c > pc) {
    cout << "LEFT\n";
  }
  return 0;
}
