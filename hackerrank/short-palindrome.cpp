// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) short-palindrome
// Title: Short Palindrome
// Link: https://www.hackerrank.com/challenges/short-palindrome/problem
// Idea: As we iterate through the string, we count up the number of 1-, 2-, and
// 3-letter combos that can begin a palindrome. For instance, say we are
// counting occurrences of 'a', 'ab', and 'a**'. When we reach an 'a', we add on
// a number of palindromes based on the count of 'a**'. When we reach a 'b', we
// add on to the count of 'a**' based on the count of 'ab'. Note that we need to
// be careful about the order in which we update the counts, in order to avoid
// double counting anything (see code). The runtime ends up being O(kn), where k
// is a constant factor of 26 for updating the counts.
// Difficulty: medium
// Tags: counting, complete-search
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  string s;
  cin >> s;

  // Store occurrences of each 1-, 2-, and 3- letter sequence.
  // The 3-letter sequences require that the middle two letters be equivalent.
  vector<int> singles(128, 0);                          // 'a', 'b', 'c', ...
  vector<vector<int>> pairs(128, vector<int>(128, 0));  // 'aa', 'ab', 'ac', ...
  vector<int> triples(128, 0);  // 'a**', 'b**', 'c**', ...

  int res = 0;

  for (char ch : s) {
    // Add on triples that are now completed.
    res = (triples[ch] + res) % MOD;

    for (char first = 'a'; first <= 'z'; ++first) {
      // Pairs that have a second letter equal to ch get added to
      // their respective triple.
      triples[first] = (triples[first] + pairs[first][ch]) % MOD;
      // The pairs are also updated, though we make sure to do this
      // before updating the triples to avoid counting too many triples.
      pairs[first][ch] = (pairs[first][ch] + singles[first]) % MOD;
    }

    // Finally, update the singles. Technically, the MOD is not needed since
    // |s| is only 10^6.
    singles[ch] = (singles[ch] + 1) % MOD;
  }

  cout << res << endl;

  return 0;
}
