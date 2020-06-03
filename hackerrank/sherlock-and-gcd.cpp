// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) sherlock-and-gcd
// Title: Sherlock and GCD
// Link: https://www.hackerrank.com/challenges/sherlock-and-gcd/problem
// Idea: Take the gcd of all the numbers -- if it comes out to 1, such a subset
// exists.
// Difficulty: easy
// Tags: math, gcd
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cur;
    cin >> cur;
    int a;
    for (int i = 1; i < n; ++i) {
      cin >> a;
      cur = gcd(max(cur, a), min(cur, a));
    }

    cout << (cur == 1 ? "YES" : "NO") << "\n";
  }
  return 0;
}
