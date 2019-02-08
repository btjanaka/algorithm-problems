// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10305
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n, m;
  while (GET(n) && GET(m) && (n || m)) {
    vector<vector<int>> g(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; ++i) {
      int a, b;
      GET(a);
      GET(b);
      g[a].push_back(b);
      ++in[b];
    }

    // topological sort
    queue<int> todo;
    for (int i = 1; i <= n; ++i) {
      if (in[i] == 0) todo.push(i);
    }
    bool first = true;
    while (!todo.empty()) {
      int cur = todo.front();
      todo.pop();
      if (first)
        first = false;
      else
        putchar(' ');
      printf("%d", cur);

      for (int child : g[cur]) {
        --in[child];
        if (in[child] == 0) todo.push(child);
      }
    }
    printf("\n");
  }
  return 0;
}
