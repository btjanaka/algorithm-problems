// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10895
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int m, n;
  while (GET(m) > 0) {
    GET(n);
    vector<vector<ii>> A(m, vector<ii>());
    vector<set<ii>> At(n, set<ii>());

    int cols[1010];

    // input graph
    for (int i = 0; i < m; ++i) {
      int r;
      GET(r);
      for (int j = 0; j < r; ++j) {
        GET(cols[j]);
        --cols[j];
      }
      for (int j = 0; j < r; ++j) {
        int e;
        GET(e);
        A[i].push_back({cols[j], e});
      }
    }

    // transpose
    for (int i = 0; i < m; ++i) {
      for (const ii& x : A[i]) {
        At[x.first].insert({i, x.second});
      }
    }

    // output
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
      printf("%d", (int)At[i].size());
      for (const ii& x : At[i]) {
        printf(" %d", x.first + 1);
      }
      printf("\n");
      bool first = true;
      for (const ii& x : At[i]) {
        if (first) {
          first = false;
        } else {
          putchar(' ');
        }
        printf("%d", x.second);
      }
      printf("\n");
    }
  }
  return 0;
}
