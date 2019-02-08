// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11956
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int t;
  GET(t);
  getchar();
  for (int ca = 1; ca <= t; ++ca) {
    int ch;
    int dis[100];
    memset(dis, 0, sizeof(dis));
    int pos = 0;
    while ((ch = getchar()) != '\n') {
      switch (ch) {
        case '>':
          pos = (pos + 1) % 100;
          break;
        case '<':
          pos = (pos - 1) < 0 ? 99 : (pos - 1);
          break;
        case '+':
          dis[pos] = (dis[pos] + 1) % 256;
          break;
        case '-':
          dis[pos] = (dis[pos] - 1) < 0 ? 255 : (dis[pos] - 1);
          break;
        case '.':
          break;
      }
    }

    printf("Case %d:", ca);
    for (int i = 0; i < 100; ++i) {
      printf(" %02X", dis[i]);
    }
    printf("\n");
  }
  return 0;
}
