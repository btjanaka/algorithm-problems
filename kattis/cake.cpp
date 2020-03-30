// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) cake
// Title: Cake
// Link: https://open.kattis.com/problems/cake
// Idea: Greedily divide the cake - it should always be possible to divide
// without leftovers.
// Difficulty: medium
// Tags: greedy, implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int p, q, n;
  while (GET(p) > 0) {
    GET(q);
    GET(n);
    vector<vector<int>> cake(p + 1);
    for (int i = 0; i < n; ++i) {
      int r, c;
      GET(r);
      GET(c);
      cake[r].push_back(c);
    }

    // make sure to order the columns in each row
    for (int i = 1; i <= p; ++i) {
      sort(cake[i].begin(), cake[i].end());
    }

    // remove empty rows at back
    while (cake.back().empty()) cake.pop_back();

    // divide cake
    vector<vector<int>> res;
    for (int r = 1; r < cake.size(); ++r) {
      if (!cake[r].empty()) {
        int r0 = res.size() == 0 ? 1 : res.back()[2] + 1;
        int rf = r == cake.size() - 1 ? p : r;
        int c0, cf;
        for (int i = 0; i < cake[r].size(); ++i) {
          c0 = i == 0 ? 1 : res.back()[3] + 1;
          cf = i == cake[r].size() - 1 ? q : cake[r][i];
          res.push_back({r0, c0, rf, cf});
        }
      }
    }

    for (const vector<int>& ans : res) {
      printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    }
    printf("0\n");
  }
  return 0;
}
