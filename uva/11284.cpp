// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11284
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int all_n, m;
int n;  // the stores Daniel actually uses
int all_dist[55][55];
int dist[15][15];  // the subset of dists being used for the query
int dp[15][1 << 15];
int savings[1 << 15];

int tsp(int pos, int cur) {
  if (cur == (1 << n) - 1) return dp[pos][cur] = dist[pos][0];
  if (dp[pos][cur] != -1) return dp[pos][cur];

  dp[pos][cur] = INT_MAX;
  for (int nxt = 0; nxt < n; ++nxt) {
    if (!(cur & (1 << nxt)))
      dp[pos][cur] =
          min(dp[pos][cur], dist[pos][nxt] + tsp(nxt, cur | (1 << nxt)));
  }

  return dp[pos][cur];
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    memset(all_dist, -1, sizeof(all_dist));
    GET(all_n);
    ++all_n;
    GET(m);

    // input roads and costs
    for (int i = 0; i < m; ++i) {
      int n1, n2;
      GET(n1);
      GET(n2);
      int b, d;
      scanf("%d.%d", &b, &d);
      int c = b * 100 + d;
      if (all_dist[n1][n2] != -1) {
        all_dist[n1][n2] = min(all_dist[n1][n2], c);
        all_dist[n2][n1] = min(all_dist[n2][n1], c);
      } else {
        all_dist[n1][n2] = c;
        all_dist[n2][n1] = c;
      }
    }

    // 0 distance for self loops
    for (int i = 0; i < all_n; ++i) all_dist[i][i] = 0;

    // calculate shortest paths between nodes
    for (int mid = 0; mid < all_n; ++mid) {
      for (int start = 0; start < all_n; ++start) {
        if (all_dist[start][mid] != -1) {
          for (int end = 0; end < all_n; ++end) {
            if (all_dist[mid][end] != -1) {
              int d = all_dist[start][mid] + all_dist[mid][end];
              if (all_dist[start][end] == -1)
                all_dist[start][end] = d;
              else
                all_dist[start][end] = min(all_dist[start][end], d);
            }
          }
        }
      }
    }

    // input stores and saves
    int p;
    GET(p);
    map<int, int> saves;  // how much can Daniel save at each store
    for (int i = 0; i < p; ++i) {
      int st, b, d, c;
      scanf("%d %d.%d", &st, &b, &d);
      c = b * 100 + d;
      if (saves.find(st) == saves.end()) saves[st] = 0;
      saves[st] += c;  // accounts for repeat stores
    }

    // only get the distances we need - sort of rename the stores
    n = saves.size() + 1;
    int stores[15];
    stores[0] = 0;
    int s_i = 1;
    int tot_save = 0;
    for (auto& s : saves) {
      stores[s_i++] = s.first;
      tot_save += s.second;
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = all_dist[stores[i]][stores[j]];
      }
    }

    // calculate savings of all subsets of items - much better than
    // recalculating it later
    for (int i = 0; i < (1 << n); ++i) {
      savings[i] = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) savings[i] += saves[stores[j]];
      }
    }
    int all_saves = savings[(1 << n) - 1];

    memset(dp, -1, sizeof(dp));
    tsp(0, 1);

    // iterate through the table and try to find a solution that saves the most.
    // keep in mind each entry tells how much it would take to get the
    // *remaining* items and return home if one was at the position with that
    // amount of money
    int mx_save = INT_MIN;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < (1 << n); ++j) {
        if (dp[i][j] == -1) continue;

        int tot_saved = all_saves - savings[j];
        tot_saved += saves[stores[i]];  // amt saved by getting product here
        tot_saved -= dp[i][j];          // road cost to get home
        tot_saved -= dist[i][0];        // road cost to get here
        mx_save = max(tot_saved, mx_save);
      }
    }

    if (mx_save > 0) {
      printf("Daniel can save $%d.%02d\n", mx_save / 100, mx_save % 100);
    } else {
      printf("Don't leave the house\n");
    }
  }
  return 0;
}
