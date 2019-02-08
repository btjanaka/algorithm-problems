// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10158
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  vector<int> p, rank;
  vector<unordered_set<int>> enemies;

  UnionFind(int n) : p(n), rank(n, 0), enemies(n) {
    iota(p.begin(), p.end(), 0);
  }

  int findSet(int a) { return a == p[a] ? a : (p[a] = findSet(p[a])); }
  bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
  void unionSet(int a, int b) {
    if (!isSameSet(a, b)) {
      int x = findSet(a), y = findSet(b);
      if (rank[x] > rank[y]) {
        p[y] = x;
        for (int i : enemies[y]) {
          enemies[x].insert(i);
          enemies[i].insert(x);
        }
      } else {
        p[x] = y;
        for (int i : enemies[x]) {
          enemies[y].insert(i);
          enemies[i].insert(y);
        }
        if (rank[x] == rank[y]) ++rank[y];
      }
    }
  }

  bool setFriends(int x, int y) {
    if (areFriends(x, y)) return true;
    if (x == y) return true;
    if (areEnemies(x, y)) return false;
    unionSet(x, y);
    return true;
  }
  bool setEnemies(int x, int y) {
    if (areEnemies(x, y)) return true;
    if (x == y) return false;
    if (areFriends(x, y)) return false;
    int px = findSet(x);
    int py = findSet(y);

    // py must become friends with all enemies of px and vice versa
    for (int i : enemies[px]) {
      if (areEnemies(i, py)) return false;
    }
    for (int i : enemies[py]) {
      if (areEnemies(i, px)) return false;
    }
    for (int i : enemies[px]) {
      setFriends(i, py);
    }
    for (int i : enemies[py]) {
      setFriends(i, px);
    }

    px = findSet(x);
    py = findSet(y);
    enemies[px].insert(py);
    enemies[py].insert(px);
    return true;
  }

  bool areFriends(int x, int y) { return isSameSet(x, y); }
  bool areEnemies(int x, int y) {
    int px = findSet(x);
    int py = findSet(y);
    return enemies[px].find(py) != enemies[px].end();
  }
};

int main() {
  int n;
  GET(n);
  int c, x, y;
  UnionFind uf(n);
  while (scanf("%d %d %d", &c, &x, &y) && (c || x || y)) {
    switch (c) {
      case 1:
        if (!uf.setFriends(x, y)) {
          printf("-1\n");
        }
        break;
      case 2:
        if (!uf.setEnemies(x, y)) {
          printf("-1\n");
        }
        break;
      case 3:
        printf("%d\n", uf.areFriends(x, y));
        break;
      case 4:
        printf("%d\n", uf.areEnemies(x, y));
        break;
    }
  }
  // for (int i = 0; i < uf.enemies.size(); ++i) {
  //   printf("%2d->%2d:", i, uf.findSet(i));
  //   if (uf.findSet(i) == i) {
  //     for (int j : uf.enemies[i]) printf(" %d", j);
  //   }
  //   printf("\n");
  // }
  return 0;
}
