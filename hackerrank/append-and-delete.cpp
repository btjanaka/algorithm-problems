// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) append-and-delete
// Title: Append and Delete
// Link: https://www.hackerrank.com/challenges/append-and-delete/problem
// Idea: There are two main cases to consider. If k is >= the length of s and t
// combined, we can just delete s all the way (keep in mind what happens when
// one deletes on an empty string) and append the characters of t. Otherwise, we
// count the number of characters common to both s and t and see if k is enough
// to remove everything but the common characters from s and append the ending
// of t. But sometimes k may be a bit bigger, so we can take off and re-append a
// common character with 2 operations.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  int k;
  cin >> s >> t >> k;

  int s_n = s.size(), t_n = t.size();
  bool ok = false;
  if (k >= s_n + t_n) {
    // If we can just delete s all the way.
    ok = true;
  } else {
    // If we can remove up to the common characters (or in some cases, remove
    // some common characters as well) and append.
    int common = 0;
    while (s[common] == t[common]) ++common;
    int min_req = s_n - common + t_n - common;
    // % 2 because we need 2 operations to remove and re-append a common
    // character.
    if (k >= min_req && ((k - min_req) % 2 == 0)) ok = true;
  }

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
