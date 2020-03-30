// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) supermario169
// Title: Super Mario 169
// Link: https://open.kattis.com/problems/supermario169
// Idea: Use TSP to find distance between the coins that pop up, and between the
// switches.
// Difficulty: medium
// Tags: dynamic-programming, tsp, implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

double xyzdist(double a[3], double b[3]) {
  double dx = a[0] - b[0];
  double dy = a[1] - b[1];
  double dz = a[2] - b[2];
  return sqrt(dx * dx + dy * dy + dz * dz);
}

double dp[15][1 << 15];

void clear_dp() {
  for (int i = 0; i < 15; ++i)
    for (int j = 0; j < (1 << 15); ++j) dp[i][j] = -1.0;
}

double tsp(int pos, int visited, int n, double dist[15][15]) {
  if (visited == (1 << n) - 1) {
    return dist[pos][0];
  }
  if (dp[pos][visited] != -1.0) return dp[pos][visited];

  dp[pos][visited] = 1e9;
  for (int nxt = 0; nxt < n; ++nxt) {
    if (!(visited & (1 << nxt))) {
      dp[pos][visited] =
          min(dp[pos][visited],
              dist[pos][nxt] + tsp(nxt, visited | (1 << nxt), n, dist));
    }
  }
  return dp[pos][visited];
}

int main() {
  int n;
  int k[15];  // number of coins in each switch, plus 1 for the switch itself
  double pts[15][15][3];  // first entry in each index is switch, next are coins

  // input
  GET(n);
  ++n;  // for mario
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      // mario
      k[i] = 1;
      for (int j = 0; j < 3; ++j) {
        GED(pts[0][0][j]);
      }
      continue;
    }
    GET(k[i]);
    ++k[i];
    for (int j = 0; j < k[i]; ++j) {
      for (int l = 0; l < 3; ++l) {
        GED(pts[i][j][l]);
      }
    }
  }

  // printf("input:\n");
  // for (int i = 0; i < n; ++i) {
  //   printf("pt %d\n", i);
  //   for (int j = 0; j < k[i]; ++j) {
  //     if (j != 0) printf("  ");
  //     printf("%lf %lf %lf\n", pts[i][j][0], pts[i][j][1], pts[i][j][2]);
  //   }
  // }

  // find distances between each pair of switches
  double dist[15][15];
  for (int from = 0; from < n; ++from) {
    for (int to = 0; to < n; ++to) {
      if (from == to) {
        dist[from][to] = 0.0;
      } else {
        // calculate tsp distance btwn |from| and |to|
        double subdist[15][15];
        for (int i = 0; i < k[from]; ++i) {
          for (int j = 0; j < k[from]; ++j) {
            subdist[i][j] = xyzdist(pts[from][i], pts[from][j]);
            // the "return" dist is the distance to |to|, unless |to| is 0, in
            // which case there is no need to return at all
            if (j == 0) {
              if (to == 0) {
                subdist[i][j] = 0.0;
              } else {
                subdist[i][j] = xyzdist(pts[from][i], pts[to][0]);
              }
            }
          }
        }
        clear_dp();
        dist[from][to] = tsp(0, 1, k[from], subdist);
      }
    }
  }

  clear_dp();
  printf("%.6lf\n", tsp(0, 1, n, dist));

  return 0;
}
