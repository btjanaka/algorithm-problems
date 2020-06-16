// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) building-a-list
// Title: Building a List
// Link: https://www.hackerrank.com/challenges/building-a-list/problem
// Idea: Sort the string to ensure we always generate strings in lexicographical
// order. Then generate every subset of characters in the string and add them to
// the results. Use a set for the results to ensure that no strings are
// repeated.
// Difficulty: medium
// Tags: complete-search
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    set<string> res;
    // Iterate through all strings made from subsets of characters. Each string
    // will be organized in lexicographical order since s is sorted above.
    for (int i = 1; i < (1 << n); ++i) {
      string cur;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          cur.push_back(s[j]);
        }
      }
      res.insert(cur);
    }

    for (const auto& x : res) {
      cout << x << '\n';
    }
  }

  return 0;
}
