// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10389
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  string s;
  cin >> ca;
  getline(cin, s);
  getline(cin, s);

  while (ca--) {
    vector<pair<double, double>> coords;
    vector<int> sub;  // id of the subway

    // home is node 0, school is node 1
    double hx, hy, sx, sy;
    cin >> hx >> hy >> sx >> sy;
    getline(cin, s);
    coords.push_back({hx, hy});
    coords.push_back({sx, sy});
    sub.push_back(-1);
    sub.push_back(0);

    int cur_id = 1;

    // store all coords and their subway
    while (getline(cin, s) && s != "") {
      double x, y;
      stringstream ss(s);
      while (ss >> x >> y && !(x == -1 && y == -1)) {
        coords.push_back({x, y});
        sub.push_back(cur_id);
      }
      ++cur_id;
    }

    // construct graph - pay attn to units
    int n = coords.size();
    vector<vector<pair<int, double>>> g(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double dx = coords[i].first - coords[j].first;
        double dy = coords[i].second - coords[j].second;
        double d = sqrt(dx * dx + dy * dy) / 1000.0;
        double t =
            (sub[i] == sub[j] && j == i + 1 ? d / 40.0 : d / 10.0) * 60.0;
        g[i].push_back({j, t});
        g[j].push_back({i, t});
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   printf("%d:", i);
    //   for (int j = 0; j < g[i].size(); ++j) {
    //     printf(" %d(%lf)", g[i][j].first, g[i][j].second);
    //   }
    //   printf("\n");
    // }

    // dijkstra
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;
    pq.push({0.0, 0});
    vector<double> dist(n, 1e14);
    dist[0] = 0.0;
    while (!pq.empty()) {
      pair<double, int> cur = pq.top();
      pq.pop();
      double d = cur.first;
      int u = cur.second;
      if (d > dist[u]) continue;
      for (pair<int, double> child : g[u]) {
        int v = child.first;
        double w = child.second;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }

    printf("%d\n", (int)round(dist[1]));
    if (ca) printf("\n");
  }
  return 0;
}
