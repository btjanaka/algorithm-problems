// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11906
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int r, c, m, n, w, ri, ci;
bool water[110][110];
vector<int> dr;
vector<int> dc;
int ditr;  // how many of dr and dc to itr thru
int even, odd;
bool visited[110][110];
void dfs(int rcur, int ccur) {
  if (visited[rcur][ccur]) return;
  visited[rcur][ccur] = true;

  int count = 0;
  for (int i = 0; i < ditr; ++i) {
    int r2 = rcur + dr[i];
    int c2 = ccur + dc[i];
    if (!(r2 < 0 || r2 >= r || c2 < 0 || c2 >= c || water[r2][c2])) {
      ++count;
      dfs(r2, c2);
    }
  }

  if (count % 2 == 0) {
    ++even;
  } else {
    ++odd;
  }
}

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    GET(r);
    GET(c);
    GET(m);
    GET(n);
    GET(w);
    memset(water, false, sizeof(water));
    for (int i = 0; i < w; ++i) {
      GET(ri);
      GET(ci);
      water[ri][ci] = true;
    }

    // determine itr
    if (m == n) {
      ditr = 4;
    } else {
      ditr = 8;
    }
    dr = {m, m, -m, -m, n, n, -n, -n};
    dc = {n, -n, n, -n, m, -m, m, -m};

    if (m == 0 || n == 0) {
      int mx = max(m, n);
      dr = {mx, -mx, 0, 0};
      dc = {0, 0, mx, -mx};
    }

    memset(visited, false, sizeof(visited));
    even = odd = 0;
    dfs(0, 0);

    printf("Case %d: %d %d\n", caa, even, odd);
  }
  return 0;
}
