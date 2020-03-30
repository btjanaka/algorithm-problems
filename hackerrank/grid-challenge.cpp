// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) grid-challenge
// Title: Grid Challenge
// Link: https://www.hackerrank.com/challenges/grid-challenge/problem
// Idea: Do a bunch of sorting.
// Difficulty: easy
// Tags: implementation
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

  int ca;
  cin >> ca;

  while (ca--) {
    int n;
    cin >> n;
    cin.get();
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, grid[i]);
      sort(grid[i].begin(), grid[i].end());
    }

    bool ok = true;
    for (int c = 0; c < n; ++c) {
      for (int r = 0; r < n - 1; ++r) {
        ok &= grid[r][c] <= grid[r + 1][c];
      }
    }

    printf(ok ? "YES" : "NO");
    printf("\n");
  }
  return 0;
}
