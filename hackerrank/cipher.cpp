// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) cipher
// Title: Cipher
// Link: https://www.hackerrank.com/challenges/cipher/problem
// Idea: Keep a count of how many bits we expect to see at each position. If the
// count is odd, we expect to see "1", and if the count is even, we expect to
// see "0". Sometimes, this won't match up though - when it doesn't, we know a 1
// was added into the number.
// Difficulty:
// Tags:
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> encoded(n + k - 1);
  for (int i = 0; i < n + k - 1; ++i) scanf("%1d", &encoded[i]);

  // Keep a running count of number of "on" bits in the last k positions
  int count = 0;
  vector<int> res(n, 0);
  for (int i = 0; i < n; ++i) {
    if (i >= k && res[i - k] == 1) --count;

    int expected = count % 2;
    if (expected != encoded[i]) {
      ++count;
      res[i] = 1;
    }
  }

  for (int i = 0; i < n; ++i) printf("%1d", res[i]);
  printf("\n");

  return 0;
}
