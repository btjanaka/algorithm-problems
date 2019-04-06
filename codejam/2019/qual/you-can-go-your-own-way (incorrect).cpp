// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) You Can Go Your Own Way
// INCORRECT VERSION - attempts to count instead of outputting an actual path -
// this is why you read the problem...
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

char buf[100101];

long long grid[2][50050];

int n;

struct pair_hash {
  size_t operator()(const ii& p) const { return p.first * n + p.second; }
};

// Returns the value if the given path was not part of the map, otherwise 0
long long check(int r1, int c1, int r2, int c2, long long val,
                unordered_map<ii, ii, pair_hash>& path) {
  if (path.find({r1, c1}) != path.end() &&
      path[make_pair(r1, c1)] == make_pair(r2, c2)) {
    return 0;
  }
  return val;
}

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    GET(n);
    getchar();
    fgets(buf, 100100, stdin);

    // paths which are already taken
    unordered_map<ii, ii, pair_hash> path;
    int path_len = 2 * n - 2;
    ii cur = {0, 0};
    for (int i = 0; i < path_len; ++i) {
      ii next = cur;
      if (buf[i] == 'S')
        ++next.second;
      else
        ++next.first;
      path[cur] = next;
      cur = next;
    }

    // Debugging
    // for (const auto& x : path) {
    //   printf("%d %d -> %d %d\n", x.first.first, x.first.second,
    //   x.second.first,
    //          x.second.second);
    // }

    long long res = 0;
    memset(grid, 0, sizeof(grid));
    for (int r = n - 1; r >= 0; --r) {
      int cur = r % 2, prev = 1 - r % 2;
      for (int c = n - 1; c >= 0; --c) {
        if (c == n - 1) {
          if (r == n - 1) {
            grid[cur][c] = 1;  // base case
          } else {
            grid[cur][c] = check(r, c, r + 1, c, grid[prev][c], path);
          }
        } else {
          grid[cur][c] = check(r, c, r, c + 1, grid[cur][c + 1], path);
          if (r != n - 1) {
            grid[cur][c] += check(r, c, r + 1, c, grid[prev][c], path);
          }
        }
        if (r == 0 && c == 0) {
          res = grid[cur][0];
        }
      }
    }

    printf("Case #%d: %lld\n", caa, res);
  }
  return 0;
}
