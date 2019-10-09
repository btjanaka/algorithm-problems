// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) ctci-ransom-note
// Title: Hash Tables: Ransom Note
// Link: https://www.hackerrank.com/challenges/ctci-ransom-note/problem
// Idea: Use hash tables and store counts.
// Difficulty: easy
// Tags: hash-table
#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  unordered_map<string, int> magazine;
  unordered_map<string, int> note;

  string s;
  while (m--) {
    cin >> s;
    ++magazine[s];
  }
  while (n--) {
    cin >> s;
    ++note[s];
  }

  bool can_make = true;
  for (const auto& word : note) {
    can_make &= word.second <= magazine[word.first];
  }

  cout << (can_make ? "Yes" : "No") << "\n";

  return 0;
}
