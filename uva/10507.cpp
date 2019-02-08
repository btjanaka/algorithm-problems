// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10507
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n, m;
  char buf[5];
  while (GET(n) > 0) {
    vector<unordered_set<int>> graph(26, unordered_set<int>());

    int wake = 0;  // bitset
    GET(m);
    getchar();
    fgets(buf, 5, stdin);
    for (int i = 0; i < 3; ++i) {
      wake |= 1 << (buf[i] - 'A');
    }
    int totw = 3;

    for (int i = 0; i < m; ++i) {
      char c1, c2;
      scanf(" %c%c", &c1, &c2);
      c1 -= 'A';
      c2 -= 'A';
      graph[c1].insert(c2);
      graph[c2].insert(c1);
    }

    bool ok = false;
    int yrs = 0;
    if (totw == n) {
      ok = true;
    } else {
      while (true) {
        vector<int> new_wake;
        for (int i = 0; i < 26; ++i) {
          if (wake & (1 << i)) continue;
          int con = 0;
          for (int x : graph[i]) {
            if (wake & (1 << x)) ++con;
          }
          if (con >= 3) new_wake.push_back(i);
        }
        for (int i : new_wake) {
          ++totw;
          wake |= (1 << i);
        }
        ++yrs;
        if (totw == n) {
          ok = true;
          break;
        }
        if (new_wake.size() == 0) break;
      }
    }

    if (ok) {
      printf("WAKE UP IN, %d, YEARS\n", yrs);
    } else {
      printf("THIS BRAIN NEVER WAKES UP\n");
    }
  }
  return 0;
}
