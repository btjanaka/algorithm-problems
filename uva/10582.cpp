// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10582
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int tot;
int m, n;

// o - blank
// - - single line
// x - corner
char grid[64][64];
char buf[2][500];

void backtrack(int r, int c, int rp, int cp, set<pair<int, int>>& seen) {
  if (r == m - 1 && c == n - 1) {
    ++tot;
    return;
  }

  if (seen.find(make_pair(r, c)) != seen.end()) return;
  seen.insert(make_pair(r, c));

  switch (grid[r][c]) {
    case 'o':
      return;
    case '-':
      if (rp == r - 1 && r < m - 1) backtrack(r + 1, c, r, c, seen);
      if (rp == r + 1 && r > 0) backtrack(r - 1, c, r, c, seen);
      if (cp == c - 1 && c < n - 1) backtrack(r, c + 1, r, c, seen);
      if (cp == c + 1 && c > 0) backtrack(r, c - 1, r, c, seen);
      break;
    case 'x':
      if (rp == r - 1 || rp == r + 1) {
        if (c > 0) backtrack(r, c - 1, r, c, seen);
        if (c < n - 1) backtrack(r, c + 1, r, c, seen);
      }
      if (cp == c - 1 || cp == c + 1) {
        if (r > 0) backtrack(r - 1, c, r, c, seen);
        if (r < m - 1) backtrack(r + 1, c, r, c, seen);
      }
      break;
  }

  seen.erase(make_pair(r, c));
}

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    tot = 0;
    GET(m);
    GET(n);
    getchar();
    FOR(i, 0, m) {
      fgets(buf[0], 500, stdin);
      fgets(buf[0], 500, stdin);
      FOR(j, 0, 2) { fgets(buf[j], 500, stdin); }
      for (int j = 0; j < n; ++j) {
        int x = j * 4 + 1;
        if (buf[0][x] == '*' && buf[0][x + 1] == '*' && buf[0][x + 2] == '*') {
          grid[i][j] = '-';
        } else if (buf[0][x] == '*' && buf[0][x + 1] == '*' &&
                   buf[1][x + 1] == '*') {
          grid[i][j] = 'x';
        } else {
          grid[i][j] = 'o';
        }
      }
    }
    fgets(buf[0], 500, stdin);
    set<pair<int, int>> seen;
    backtrack(0, 0, -1, -1, seen);
    printf("Number of solutions: %d\n", tot);
  }
  return 0;
}
