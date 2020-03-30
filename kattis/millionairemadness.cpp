// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) millionairemadness
// Title: Millionaire Madness
// Link: https://open.kattis.com/problems/millionairemadness
// Idea: Binary search for a ladder height that works; check the ladder height
// with BFS.
// Difficulty: medium
// Tags: binary-search, graph, breadth-first-search
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int coins[1010][1010];
int m, n;
int last;

int key(int r, int c) { return r * n + c; }
pair<int, int> coord(int key) { return {key / n, key % n}; }

bool height_works(int from, int to, int cur_height) {
  return from >= to || to - from <= cur_height;
}

// Do bfs to find out if the height works
bool works(int height) {
  queue<int> to_visit;
  to_visit.push(0);
  unordered_set<int> visited;
  visited.insert(0);
  while (!to_visit.empty()) {
    int cur = to_visit.front();
    to_visit.pop();

    if (cur == last) return true;

    pair<int, int> rc = coord(cur);
    int r = rc.first, c = rc.second;

    int north = key(r - 1, c);
    int south = key(r + 1, c);
    int east = key(r, c + 1);
    int west = key(r, c - 1);
    int cur_height = coins[r][c];
    if (r < m - 1 && visited.find(south) == visited.end() &&
        height_works(cur_height, coins[r + 1][c], height)) {
      to_visit.push(south);
      visited.insert(south);
    }
    if (r > 0 && visited.find(north) == visited.end() &&
        height_works(cur_height, coins[r - 1][c], height)) {
      to_visit.push(north);
      visited.insert(north);
    }
    if (c > 0 && visited.find(west) == visited.end() &&
        height_works(cur_height, coins[r][c - 1], height)) {
      to_visit.push(west);
      visited.insert(west);
    }
    if (c < n - 1 && visited.find(east) == visited.end() &&
        height_works(cur_height, coins[r][c + 1], height)) {
      to_visit.push(east);
      visited.insert(east);
    }
  }
  return false;
}

int main() {
  GET(m);
  GET(n);
  last = key(m - 1, n - 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      GET(coins[i][j]);
    }
  }
  int lo = 0, hi = 1000000000, ans = 0;
  while (hi != lo) {
    int mid = lo + (hi - lo) / 2;
    if (works(mid)) {
      hi = mid;
      ans = mid;
    } else {
      lo = mid + 1;
      ans = mid + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
