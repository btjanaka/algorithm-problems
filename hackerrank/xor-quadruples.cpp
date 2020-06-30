// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) xor-quadruples
// Title: Beautiful Quadruples
// Link: https://www.hackerrank.com/challenges/xor-quadruples/problem
// Idea: First note that for two numbers g and h, g xor h = 0 iff g == h. Now,
// we can split the quadruple into (a xor b) and (c xor d). Essentially, we
// calculate possible values of these two pairs and then check which xor values
// can be obtained by both pairs. Every time there is a match, we subtract from
// the total number of pairs. Things become complicated because we are asked to
// count the number of unique quadruples. We can ensure we go through unique
// quadruples by sorting a, b, c, d. As we come up with the values of a xor b,
// we store the items that made each value, sorted by b. Finally, when we create
// c xor d, we can check how many of the xor values conflict by looking at these
// stored lists.
// Difficulty: medium
// Tags: complete-search, implementation
#include <bits/stdc++.h>

using namespace std;

int main() {
  int vals[4];
  cin >> vals[0] >> vals[1] >> vals[2] >> vals[3];
  sort(vals, vals + 4);

  // Find all the a xor b values.
  unordered_map<int, vector<pair<int, int>>>
      locs;  // Maps xor value to list of (b,a) values that made it.
  for (int a = 1; a <= vals[0]; ++a) {
    for (int b = a; b <= vals[1]; ++b) {
      locs[a ^ b].push_back({b, a});
    }
  }
  // Sort all the location lists by b.
  for (auto& x : locs) {
    sort(x.second.begin(), x.second.end());
  }

  // Go through all c xor d values.
  long long res = 0;
  for (int c = 1; c <= vals[2]; ++c) {
    for (int d = c; d <= vals[3]; ++d) {
      // Here we calculate the number of a,b pairs that the current values of c
      // and d would match to. This is essentially an arithmetic sequence, as
      // a = 1 will have b values, a = 2 will have b-1 values, ...
      // We use z and y instead of b and a because the sorting requires that
      // both values are less than c (we generate quadruples in non-decreasing
      // order).
      int z = min(c, vals[1]);
      int y = min(c, vals[0]);
      long long num_values = (z + z - y + 1) * y / 2;

      // Here we find the number of conflicts between c xor d and a xor b.
      int x = c ^ d;
      if (locs.find(x) != locs.end()) {
        // We only count conflicts with a b value <= to the value of c, again
        // because sequences are in ascending order.
        int bad_values =
            lower_bound(locs[x].begin(), locs[x].end(), make_pair(c, 4000)) -
            locs[x].begin();
        num_values -= bad_values;
      }
      res += num_values;
    }
  }
  cout << res << endl;

  // This may help: It shows what a brute force solution that generates unique
  // quadruples would look like.
  // {
  //     int tot = 0, res = 0;
  //     for(int a = 1; a <= vals[0]; ++a) {
  //         for(int b = a; b <= vals[1]; ++b) {
  //             for(int c = b; c <= vals[2]; ++c) {
  //                 for(int d = c; d <= vals[3]; ++d) {
  //                     ++tot;
  //                     if((a ^ b ^ c ^ d) != 0) {
  //                         ++res;
  //                     }
  //                 }
  //             }
  //         }
  //     }
  //     cout << "real:" << res << endl;
  //     cout << "total:" << tot << endl;
  // }

  return 0;
}
