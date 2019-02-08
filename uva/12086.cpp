// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12086
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;

int p[200005];

struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int lsone(int i) { return i & (-i); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= lsone(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += lsone(k)) ft[k] += v;
  }
};

int main() {
  int n;
  char buf[100];
  for (int ca = 1; GET(n) && n; ++ca) {
    if (ca != 1) printf("\n");
    printf("Case %d:\n", ca);

    FenwickTree ft(n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      ft.adjust(i, p[i]);
    }

    char ch;
    int x, y;
    while (scanf("%s", buf) && strcmp(buf, "END") != 0) {
      GET(x);
      GET(y);
      if (buf[0] == 'M') {
        printf("%d\n", ft.rsq(x, y));
      } else if (buf[0] == 'S') {
        ft.adjust(x, y - p[x]);
        p[x] = y;
      }
    }
  }
  return 0;
}
