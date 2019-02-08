// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11991
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) > 0) {
    unordered_map<int, vector<int>> pos;
    int x;
    for (int i = 0; i < n; ++i) {
      GET(x);
      if (pos.find(x) == pos.end()) {
        pos[x] = vector<int>();
      }
      pos[x].push_back(i + 1);
    }

    int k, v;
    for (int i = 0; i < m; ++i) {
      GET(k);
      GET(v);
      if (pos.find(v) == pos.end() || k > pos[v].size()) {
        printf("0\n");
      } else {
        printf("%d\n", pos[v][k - 1]);
      }
    }
  }
  return 0;
}
