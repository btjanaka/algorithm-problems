// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) abbreviation
// Title: Abbreviation
// Link: https://www.hackerrank.com/challenges/abbr/problem
// Idea: See formula in main. This is a dynamic programming problem similar to
// longest common subsequence.
// Difficulty: medium
// Tags: dynamic-programming, DP, longest-common-subsequence, lcs
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  string a, b;
  for (int ca = 0; ca < q; ++ca) {
    cin >> a >> b;

    int len_a = a.size();
    int len_b = b.size();
    int a_last_upper_idx;
    for (a_last_upper_idx = len_a - 1; islower(a[a_last_upper_idx]);
         --a_last_upper_idx)
      ;

    // DP table - [i][j] tells if is is possible to solve the problem with
    // strings starting at index i in a and index j in b.
    vector<vector<bool>> possible(len_a + 1, vector<bool>(len_b + 1, false));

    // Iterate in such a manner to account for dependencies of table values.
    for (int j = len_b; j >= 0; --j) {
      for (int i = len_a; i >= 0; --i) {
        if (j == len_b) {
          // If we reached the end of string b, we are good, except when not all
          // uppercase letters in a have been consume.
          possible[i][j] = i > a_last_upper_idx;
        } else if (i == len_a) {
          // If i is at the end we failed.
          possible[i][j] = false;
        } else if (isupper(a[i])) {
          // Uppercase letters are required to match - when they do, we advance
          // both indices.
          if (a[i] == b[j]) {
            possible[i][j] = possible[i + 1][j + 1];
          } else {
            possible[i][j] = false;
          }
        } else {
          // Lowercase letters are either made uppercase or skipped.
          if (toupper(a[i]) == b[j]) {
            possible[i][j] = possible[i + 1][j + 1] || possible[i + 1][j];
          } else {
            possible[i][j] = possible[i + 1][j];
          }
        }
      }
    }

    printf(possible[0][0] ? "YES\n" : "NO\n");
  }
  return 0;
}
