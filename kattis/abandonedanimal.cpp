// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) abandonedanimal
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, m;
  string s;
  while (cin >> n) {
    // input the stores
    cin >> k;
    unordered_map<string, vector<int>> stores;
    for (int i = 0; i < k; ++i) {
      int x;
      cin >> x >> s;
      if (stores.find(s) == stores.end()) {
        stores[s] = {};
      }
      stores[s].push_back(x);
    }

    // go through items - each time, add on the next set of stores
    cin >> m;
    unordered_map<int, int> a1, a2;
    a1[-1] = 1;
    int tot = 0;
    for (int i = 0; i < m; ++i) {
      unordered_map<int, int>& cur = i % 2 == 0 ? a1 : a2;
      unordered_map<int, int>& next = i % 2 == 0 ? a2 : a1;

      cin >> s;
      next.clear();
      for (auto x : cur) {
        for (int j : stores[s]) {
          if (j >= x.first) {
            if (next.find(j) == next.end()) {
              next[j] = 0;
            }
            next[j] += x.second;
          }
        }
      }

      if (i == m - 1) {
        for (auto x : next) {
          tot += x.second;
        }
      }
    }

    // output
    switch (tot) {
      case 0:
        printf("impossible\n");
        break;
      case 1:
        printf("unique\n");
        break;
      default:
        printf("ambiguous\n");
        break;
    }
  }
  return 0;
}
