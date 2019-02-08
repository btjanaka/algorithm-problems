// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11034
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    // input
    int l, m;
    GET(l);
    GET(m);
    l *= 100;  // convert to cm
    queue<int> left, right;
    char side[10];
    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d %s", &x, side);
      if (strcmp(side, "left") == 0) {
        left.push(x);
      } else {
        right.push(x);
      }
    }

    // simulation
    int res = 0;
    int pos = false;  // false = left, true = right
    while (!(left.empty() && right.empty())) {
      int tot = 0;
      queue<int>& posq = pos ? right : left;
      while (!posq.empty() && tot + posq.front() <= l) {
        tot += posq.front();
        posq.pop();
      }

      ++res;
      pos = !pos;
    }

    // output
    printf("%d\n", res);
  }
  return 0;
}
