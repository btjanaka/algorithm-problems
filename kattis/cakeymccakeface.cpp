// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) cakeymccakeface
// Title: Cakey McCakeFace
// Link: https://open.kattis.com/problems/cakeymccakeface
// Idea: Brute force through all possible differences and see which one gives
// the best correspondence.
// Difficulty: easy
// Tags: brute-force
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int n, m;
  while (GET(n) > 0) {
    GET(m);
    vector<int> enter(n), exit(m);
    for (int i = 0; i < n; ++i) GET(enter[i]);
    for (int i = 0; i < m; ++i) GET(exit[i]);

    // calculate all possible differences
    map<int, int> diffs;  // important for ordering
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int d = exit[j] - enter[i];
        if (d >= 0) {
          if (diffs.find(d) == diffs.end()) diffs[d] = 0;
          ++diffs[d];
        }
      }
    }

    // find max diff
    int res_count = -1;
    int res_d = 0;
    for (auto d : diffs) {
      if (d.second > res_count) {
        res_d = d.first;
        res_count = d.second;
      }
    }

    printf("%d\n", res_d);
  }
  return 0;
}
