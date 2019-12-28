// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) equal
// Title: Equal
// Link: https://www.hackerrank.com/challenges/equal/problem
// Idea: See it as the inverse problem of trying to subtract 1,2, or 5 candies
// from each person they are all equal. This in turn transforms into a problem
// of seeing how many operations it takes to bring each person down to the
// lowest number of candies.
// Difficulty: medium
// Tags: greedy, dynamic-programming
#include <bits/stdc++.h>

using namespace std;

int main() {
  // Number of operations to bring each number down to 0. The problem limits the
  // number of candies for each person to 1000, but we put 2000 to be safe.
  vector<int> ops(2001);
  for (int i = 0; i <= 2000; ++i) {
    int n = i;
    ops[i] = n / 5;
    n %= 5;
    ops[i] += n / 2;
    n %= 2;
    ops[i] += n;
  }

  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mn = *min_element(a.begin(), a.end());

    int num_res = 5;
    vector<int> res(num_res);
    for (int x : a) {
      for (int i = 0; i < num_res; ++i) {
        // Add up the number of operations. There are actually 5 different
        // results because sometimes it is not optimal to bring everyone down to
        // the minimum. Rather, everyone should go down to (min - i), where i is
        // limited to [0,5) -- in the original problem, this translates to
        // everyone receiving more candy.
        res[i] += ops[x - mn + i];
      }
    }
    cout << *min_element(res.begin(), res.end()) << endl;
  }

  return 0;
}
