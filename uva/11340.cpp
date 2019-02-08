// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11340
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  GET(n);
  while (n--) {
    int k;
    GET(k);
    unordered_map<char, int> cost;
    for (int i = 0; i < k; ++i) {
      char ch;
      int c;
      scanf(" %c %d", &ch, &c);
      cost[ch] = c;
    }

    int m;
    GET(m);
    getchar();
    char ch;
    ll res = 0;
    for (int i = 0; i < m; ++i) {
      while ((ch = getchar()) != '\n') {
        if (cost.find(ch) != cost.end()) res += cost[ch];
      }
    }

    printf("%lld.", res / 100);
    ll cents = res % 100;
    if (cents < 10) {
      printf("0%lld$\n", cents);
    } else {
      printf("%lld$\n", cents);
    }
  }
  return 0;
}
