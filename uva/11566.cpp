// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11566
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int n, k, x, t;

int cost[110];
int max_cost;
int max_dishes;
int max_id;
int favor[220];  // store each mean favor twice to simulate 2x dishes
                 // costs stored at id / 2

// max cost is 2200 because at most 2 * (N + 1) dishes at $100 each
int dp[220][2205][25];  // id, cur_cost, dishes

int backtrack(int id, int cur_cost, int dishes) {
  if (dp[id][cur_cost][dishes] >= 0.0) {
    return dp[id][cur_cost][dishes];
  }

  if (id == max_id || dishes == max_dishes) {
    dp[id][cur_cost][dishes] = 0.0;
  } else if (cur_cost + cost[id / 2] > max_cost) {
    dp[id][cur_cost][dishes] = backtrack(id + 1, cur_cost, dishes);
  } else {
    double without = backtrack(id + 1, cur_cost, dishes);
    double with =
        favor[id] + backtrack(id + 1, cur_cost + cost[id / 2], dishes + 1);
    dp[id][cur_cost][dishes] = max(without, with);
  }

  return dp[id][cur_cost][dishes];
}

int main() {
  while (scanf("%d %d %d %d", &n, &x, &t, &k) && !(!n && !x && !t && !k)) {
    // input
    int buf;
    for (int i = 0; i < k; ++i) {
      GET(cost[i]);
      favor[2 * i] = 0.0;
      for (int j = 0; j < n + 1; ++j) {
        GET(buf);
        favor[2 * i] += buf;
      }
      favor[2 * i + 1] = favor[2 * i];
    }
    max_dishes = 2 * (n + 1);
    max_id = 2 * k;

    // tricky... took it from
    // https://github.com/AyaElymany/UVA-11566-Let-s-Yum-Cha-/blob/master/Let'sYumCha!.cpp
    // :D
    max_cost = floor(double(1.0 * (n + 1) * x) / 1.1 + 1e-6) - (n + 1) * t;

    // reset
    for (int i = 0; i < 220; ++i) {
      for (int j = 0; j < 2205; ++j) {
        for (int k = 0; k < 25; ++k) {
          dp[i][j][k] = -1.0;
        }
      }
    }

    // output
    printf("%.2lf\n", (double)backtrack(0, 0, 0) / (double)(n + 1));
  }
  return 0;
}
