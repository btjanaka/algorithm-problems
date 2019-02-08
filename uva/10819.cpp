// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10819
// Based on:
// https://saicheems.wordpress.com/2013/09/06/uva-10819-trouble-of-13-dots/
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// first: price (p)
// second: favor (f)
pair<int, int> items[110];
int dp[110][10500];
int m, n;

// req: must have at most that amount remaining at the end
int backtrack(int id, int cur) {
  if (cur > m && m <= 1800) return -1000;  // No bonus for <= 1800
  if (cur > m + 200) return -1000;  // Definitely invalid if exceeds 200 over
  if (id == n) {
    if (cur > m && cur <= 2000)
      return -1000;  // Ok to exceed but if less than 2000 no bonus
    return 0;  // At this point we have a value that is guaranteed <= m + 200,
               // and guaranteed to be more than 2000 if it exceeds m
  }
  if (dp[id][cur] != -1) return dp[id][cur];

  return dp[id][cur] =
             max(backtrack(id + 1, cur),
                 items[id].second + backtrack(id + 1, cur + items[id].first));
}

int main() {
  while (GET(m) > 0) {
    GET(n);

    for (int i = 0; i < n; ++i) {
      GET(items[i].first);
      GET(items[i].second);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", backtrack(0, 0));
  }
  return 0;
}
