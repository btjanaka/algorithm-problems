// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10036
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int a[10010];
char dp[10010][110];  // each one tells whether it is possible to get divisible
                      // when you are at that index with that amt (mod k)
int n, k;
char f(int id, int mod) {
  if (dp[id][mod] != '?') return dp[id][mod];

  if (id == n) {
    dp[id][mod] = mod == 0;
  } else {
    if (id == 0) {
      // special case for id = 0; always take the val
      int next = a[id] % k;
      if (next < 0) next += k;
      dp[id][mod] = f(id + 1, next);
    } else {
      int add = (mod + a[id]) % k;
      if (add < 0) add += k;
      int sub = (mod - a[id]) % k;
      if (sub < 0) sub += k;
      dp[id][mod] = f(id + 1, add) || f(id + 1, sub);
    }
  }

  return dp[id][mod];
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    GET(n);
    GET(k);
    for (int i = 0; i < n; ++i) GET(a[i]);

    memset(dp, '?', sizeof(dp));
    if (f(0, 0)) {
      printf("Divisible\n");
    } else {
      printf("Not divisible\n");
    }
  }
  return 0;
}
