// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 166
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
using namespace std;

int c[6] = {1, 2, 4, 10, 20, 40};

int main() {
  while (true) {
    int cn[6];
    bool ok = false;
    for (int i = 0; i < 6; ++i) {
      GET(cn[i]);
      ok |= cn[i];
    }
    if (!ok) break;

    int b, d;
    scanf("%d.%d", &b, &d);
    int n = (b * 100 + d) / 5;

    // make a new coins vector where each coin appears the number of times it is
    // in the input
    vector<int> cc;
    int mx_you = 0;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < cn[i]; ++j) {
        cc.push_back(c[i]);
        mx_you += c[i];
      }
    }

    // for (int i = 0; i < cc.size(); ++i) {
    //   printf("%d%c", cc[i], i == cc.size() - 1 ? '\n' : ' ');
    // }

    // build up a table consisting of the minimum number of coins to reach all
    // of the values your coins can reach
    vector<int> dp_you(mx_you + 1, -1);
    dp_you[0] = 0;
    for (int j = 0; j < cc.size(); ++j) {
      for (int i = mx_you; i >= 0; --i) {
        if (dp_you[i] == -1) continue;
        int next = i + cc[j];
        if (next > mx_you) continue;
        if (dp_you[next] == -1)
          dp_you[next] = dp_you[i] + 1;
        else
          dp_you[next] = min(dp_you[next], dp_you[i] + 1);
      }
    }

    // build up a table consisting of the minimum number of coins the shopkeeper
    // can give to reach all the possible values of change that the customer can
    // give
    int mx_change = mx_you - n;
    vector<int> dp_shop(mx_change + 1, -1);
    dp_shop[0] = 0;
    for (int i = 0; i <= mx_change; ++i) {
      if (dp_shop[i] == -1) continue;
      for (int j = 0; j < 6; ++j) {
        int next = c[j] + i;
        if (next > mx_change) continue;
        if (dp_shop[next] == -1)
          dp_shop[next] = dp_shop[i] + 1;
        else
          dp_shop[next] = min(dp_shop[next], dp_shop[i] + 1);
      }
    }

    // changing hands = either you give the exact change or you give a certain
    // amount and get change back
    // So we go through all possible amounts you can give and see which one
    // results in the least coins changing hands. The number of coins that
    // change hands can be found by looking at the dp table for you and the shop
    // at the appropriate points.
    int mn_coins = INT_MAX;
    for (int i = n; i < dp_you.size(); ++i) {
      if (dp_you[i] != -1 && dp_shop[i - n] != -1) {
        mn_coins = min(mn_coins, dp_you[i] + dp_shop[i - n]);
      }
    }

    printf("%3d\n", mn_coins);
  }
  return 0;
}
