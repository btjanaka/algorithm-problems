// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11367
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct node {
  int x;
  int fuel;
  int price;

  node(int x_, int fuel_, int price_) : x(x_), fuel(fuel_), price(price_) {}
  bool operator<(const node& rhs) const { return price < rhs.price; }
  bool operator>(const node& rhs) const { return price > rhs.price; }
};

int main() {
  int n, m;
  while (GET(n) > 0) {
    GET(m);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) GET(p[i]);

    vector<vector<ii>> g(n);
    for (int i = 0; i < m; ++i) {
      int u, v, d;
      GET(u);
      GET(v);
      GET(d);
      g[u].push_back({v, d});
      g[v].push_back({u, d});
    }

    int q;
    GET(q);
    for (int i = 0; i < q; ++i) {
      int s, e, c;
      GET(c);
      GET(s);
      GET(e);

      // construct a "state-space" graph where the state is represented by the
      // (node, fuel) - then there are 0-weight edges between two states
      // (x, fuel_x) and (y, fuel_x - dist(x, y)), as well as p[x]-weight edges
      // between (x, fuel_x) and (x, fuel_x + 1)
      vector<vector<vector<node>>> states(n, vector<vector<node>>(c + 1));
      for (int x = 0; x < n; ++x) {
        for (int fuel = 0; fuel <= c; ++fuel) {
          if (fuel != c) {
            states[x][fuel].push_back(node(x, fuel + 1, p[x]));
          }
          for (ii child : g[x]) {
            int y = child.first, d = child.second;
            if (fuel - d >= 0) {
              states[x][fuel].push_back(node(y, fuel - d, 0));
            }
          }
        }
      }

      // use dijkstra to see whether the end is reachable
      vector<vector<int>> price(n, vector<int>(c + 1, -1));
      price[s][0] = 0;
      priority_queue<node, vector<node>, greater<node>> pq;
      pq.push(node(s, 0, 0));
      while (!pq.empty()) {
        node x = pq.top();
        pq.pop();
        if (x.price > price[x.x][x.fuel] && price[x.x][x.fuel] != -1) continue;
        for (node y : states[x.x][x.fuel]) {
          if (price[x.x][x.fuel] + y.price < price[y.x][y.fuel] ||
              price[y.x][y.fuel] == -1) {
            price[y.x][y.fuel] = price[x.x][x.fuel] + y.price;
            pq.push(node(y.x, y.fuel, price[y.x][y.fuel]));
          }
        }
      }

      // final output
      if (all_of(price[e].begin(), price[e].end(),
                 [](int i) { return i == -1; })) {
        printf("impossible\n");
      } else {
        int min_price = INT_MAX;
        for (int i = 0; i <= c; ++i) {
          // printf("%d %d\n", i, price[e][i]);
          if (price[e][i] < min_price && price[e][i] != -1) {
            min_price = price[e][i];
          }
        }
        printf("%d\n", min_price);
      }
    }
  }
  return 0;
}
