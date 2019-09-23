// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 821
// Title: Page Hopping
// Link:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=762
// Idea: Floyd-Warshall
// Difficulty: easy
// Tags: all-pairs-shortest-paths, apsp
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  for (int ca = 1;; ++ca) {
    // input
    unordered_map<int, unordered_map<int, int>> g;
    int e = 0;
    int i, j;
    while (GET(i) && GET(j) && (i || j)) {
      ++e;
      g[i][j] = 1;
    }
    if (e == 0) break;

    // complete the graph
    vi nums;
    for (const auto& x : g) nums.push_back(x.first);
    for (int i : nums) {
      for (int j : nums) {
        if (i == j)
          g[i][j] = 0;
        else if (g[i].find(j) == g[i].end())
          g[i][j] = INT_MAX / 3;
      }
    }

    // Floyd-Warshall
    for (int k : nums)
      for (int i : nums)
        for (int j : nums) g[i][j] = min(g[i][k] + g[k][j], g[i][j]);

    // Calculate average
    int tot_length = 0;
    int tot = 0;
    for (int i : nums) {
      for (int j : nums) {
        if (i != j) {
          tot_length += g[i][j];
          ++tot;
        }
      }
    }

    printf("Case %d: average length between pages = %.3lf clicks\n", ca,
           double(tot_length) / tot);
  }
  return 0;
}
