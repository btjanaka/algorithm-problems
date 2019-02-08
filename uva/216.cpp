// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 216
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// brute force - passes time limit but not quite as efficient as tsp

// int main() {
//   int n;
//   ii comp[10];
//   double dist[10][10];
//   for (int ca = 1; GET(n) && n; ++ca) {
//     // input
//     for (int i = 0; i < n; ++i) {
//       GET(comp[i].first);
//       GET(comp[i].second);
//     }

//     // generate distance graph
//     for (int i = 0; i < n; ++i) {
//       for (int j = 0; j < n; ++j) {
//         dist[i][j] = 16.0 + sqrt((comp[i].first - comp[j].first) *
//                                      (comp[i].first - comp[j].first) +
//                                  (comp[i].second - comp[j].second) *
//                                      (comp[i].second - comp[j].second));
//       }
//     }

//     // iterate through all permutations of nodes (brute force because input
//     is
//     // so small)
//     int nodes[10];
//     int res[10];
//     iota(nodes, nodes + n, 0);
//     memcpy(res, nodes, n * sizeof(int));

//     double mn = 0.0;
//     for (int i = 1; i < n; ++i) {
//       mn += dist[nodes[i]][nodes[i - 1]];
//     }
//     while (next_permutation(nodes, nodes + n)) {
//       double tot = 0.0;
//       for (int i = 1; i < n; ++i) {
//         tot += dist[nodes[i]][nodes[i - 1]];
//       }
//       if (tot < mn) {
//         mn = tot;
//         memcpy(res, nodes, n * sizeof(int));
//       }
//     }

//     // output
//     printf("**********************************************************\n");
//     printf("Network #%d\n", ca);
//     for (int i = 1; i < n; ++i) {
//       printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf
//       feet.\n",
//              comp[res[i - 1]].first, comp[res[i - 1]].second,
//              comp[res[i]].first, comp[res[i]].second, dist[res[i]][res[i -
//              1]]);
//     }
//     printf("Number of feet of cable required is %.2lf.\n", mn);
//   }
//   return 0;
// }

// tsp solution

int n;
int x[10], y[10];
double g[10][10];
pair<double, ii> dp[10][1 << 10][10];  // each one stores value as well as index
                                       // of next - extra dimension to handle
                                       // storing next for all starting nodes
pair<double, ii> tsp(int pos, int cur, int start) {
  if (cur == (1 << n) - 1) {
    dp[pos][cur][start].first = 0.0;
    return dp[pos][cur][start];
  }
  if (dp[pos][cur][start].first != -1) return dp[pos][cur][start];

  dp[pos][cur][start].first = 1e9;
  for (int nxt = 0; nxt < n; ++nxt) {
    if (!(cur & (1 << nxt))) {
      double dist = g[pos][nxt] + tsp(nxt, cur | (1 << nxt), start).first;
      if (dist < dp[pos][cur][start].first) {
        dp[pos][cur][start] = {dist, {nxt, cur | (1 << nxt)}};
      }
    }
  }

  return dp[pos][cur][start];
}

int main() {
  for (int ca = 1; GET(n) && n; ++ca) {
    // input and generate graph
    for (int i = 0; i < n; ++i) {
      GET(x[i]);
      GET(y[i]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] = 16.00 + sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                               (y[i] - y[j]) * (y[i] - y[j]));
      }
    }

    // reset dp table
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (1 << n); ++j) {
        for (int k = 0; k < n; ++k) {
          dp[i][j][k] = {-1, {-1, -1}};
        }
      }
    }

    // find minimum cable
    pair<double, ii> mn = {1e9, {-1, -1}};
    int mn_pos = 0;
    for (int i = 0; i < n; ++i) {
      if (tsp(i, 1 << i, i) < mn) {
        mn = tsp(i, 1 << i, i);
        mn_pos = i;
      }
    }

    // output
    printf("**********************************************************\n");
    printf("Network #%d\n", ca);
    pair<double, ii> cur = mn;
    int cur_pos = mn_pos;
    while (cur.second != make_pair(-1, -1)) {
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
             x[cur_pos], y[cur_pos], x[cur.second.first], y[cur.second.first],
             g[cur_pos][cur.second.first]);
      cur_pos = cur.second.first;
      cur = dp[cur.second.first][cur.second.second][mn_pos];
    }
    printf("Number of feet of cable required is %.2lf.\n", mn.first);
  }
  return 0;
}
