// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11550
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, m;
    GET(n);
    GET(m);
    int counts[30];
    int edges[30][2];
    memset(counts, 0, sizeof(counts));
    memset(edges, 0, sizeof(edges));
    int x;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        GET(x);
        counts[j] += x;
        if (x) {
          if (edges[j][0]) {
            edges[j][1] = i + 1;
          } else {
            edges[j][0] = i + 1;
          }
        }
      }
    }

    // Check if each edge only touches two nodes
    if (all_of(counts, counts + m, [](int i) { return i == 2; })) {
      // Check that no edges repeat
      set<ii> seen;
      bool ok = true;
      for (int i = 0; i < m; ++i) {
        if (seen.find({edges[i][0], edges[i][1]}) == seen.end()) {
          seen.insert({edges[i][0], edges[i][1]});
        } else {
          ok = false;
          break;
        }
      }
      if (ok)
        printf("Yes\n");
      else
        printf("No\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
