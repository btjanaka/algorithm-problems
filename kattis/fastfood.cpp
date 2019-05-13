// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) fastfood
// Title: Fast Food Prizes
// Link: https://open.kattis.com/problems/fastfood
// Idea: The key is that no two prizes share stickers. So we just have to check,
// for each prize, which sticker is the limiting factor.
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
  int ca;
  GET(ca);
  while (ca--) {
    int n, m;
    GET(n);
    GET(m);
    vector<vector<int>> req(n);
    vector<int> cost(n), stickers(m + 1);
    for (int i = 0; i < n; ++i) {
      int k;
      GET(k);
      for (int j = 0; j < k; ++j) {
        int x;
        GET(x);
        req[i].push_back(x);
      }
      GET(cost[i]);
    }
    for (int i = 1; i <= m; ++i) GET(stickers[i]);

    int tot = 0;
    for (int i = 0; i < n; ++i) {
      int mn = INT_MAX;
      for (int c : req[i]) {
        mn = min(mn, stickers[c]);
      }
      tot += mn * cost[i];
    }

    printf("%d\n", tot);
  }
  return 0;
}

