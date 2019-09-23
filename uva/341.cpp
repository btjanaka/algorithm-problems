// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 341
// Title: Non-Stop Travel
// Link:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=277
// Idea: Solve with Floyd-Warshall's algorithm for All Pairs Shortest Paths.
// Difficulty: easy
// Tags: all-pairs-shortest-paths
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int ni;
  for (int ca = 1; GET(ni) && ni > 0; ++ca) {
    vector<vi> d(ni + 1, vi(ni + 1, INT_MAX / 2));
    for (int i = 1; i <= ni; ++i) d[i][i] = 0;
    vector<vi> p(ni + 1);
    for (int i = 1; i <= ni; ++i) p[i].assign(ni + 1, i);

    // Input
    for (int i = 1; i <= ni; ++i) {
      int n;
      GET(n);
      int j, w;
      for (int k = 0; k < n; ++k) {
        GET(j);
        GET(w);
        d[i][j] = w;
      }
    }
    vector<vi> original = d;

    // Apply Floyd-Warshall
    for (int k = 1; k <= ni; ++k) {
      for (int i = 1; i <= ni; ++i) {
        for (int j = 1; j <= ni; ++j) {
          if (d[i][k] + d[k][j] < d[i][j]) {
            d[i][j] = d[i][k] + d[k][j];
            p[i][j] = p[k][j];
          }
        }
      }
    }

    // Find path
    stack<int> path;
    int start, end;
    GET(start);
    GET(end);
    int tot_delay = 0;
    path.push(end);
    while (start != end) {
      int parent = p[start][end];
      path.push(parent);
      tot_delay += original[parent][end];
      end = parent;
    }
    printf("Case %d: Path =", ca);
    while (!path.empty()) {
      printf(" %d", path.top());
      path.pop();
    }
    printf("; %d second delay\n", tot_delay);
  }
  return 0;
}
