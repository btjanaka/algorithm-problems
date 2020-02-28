// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) weighted-uniform-string
// Title: Weighted Uniform Strings
// Link: https://www.hackerrank.com/challenges/weighted-uniform-string/problem
// Idea: Find the weights of all uniform contiguous substrings and put them in a
// set. Query the set to figure out which values are indeed in U.
// Difficulty: easy
// Tags: string
#include <bits/stdc++.h>
using namespace std;

int main() {
  // Find all substrings.
  unordered_set<int> s;
  int ch, prev = 0;
  int cur_score = 0;
  while ((ch = getchar()) != '\n') {
    int score = ch - 'a' + 1;
    if (ch == prev) {
      cur_score += score;
    } else {
      cur_score = score;
    }
    s.insert(cur_score);
    prev = ch;
  }

  // Read in queries and output results.
  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    printf(s.find(x) != s.end() ? "Yes\n" : "No\n");
  }

  return 0;
}
