// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1103
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// globals for days...
bool img[220][220];
bool cpy[220][220];
bool visited[220][220];
bool visited2[220][220];
char chars[] = {'W', 'A', 'K', 'J', 'S', 'D'};
int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dj[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int h, w, w2;

// eliminates black and copies to cpy
void bfs(int si, int sj) {
  queue<ii> q;
  q.push({si, sj});
  visited[si][sj] = true;
  while (!q.empty()) {
    int ci = q.front().first;
    int cj = q.front().second;
    q.pop();

    cpy[ci][cj] = true;
    for (int i = 0; i < 8; ++i) {
      int i2 = ci + di[i];
      int j2 = cj + dj[i];
      if (i2 >= 0 && i2 < h && j2 >= 0 && j2 < w && img[i2][j2] &&
          !visited[i2][j2]) {
        visited[i2][j2] = true;
        q.push({i2, j2});
      }
    }
  }
}

// eliminates white
void bfs2(int si, int sj) {
  queue<ii> q;
  q.push({si, sj});
  visited2[si][sj] = true;
  while (!q.empty()) {
    int ci = q.front().first;
    int cj = q.front().second;
    q.pop();

    for (int i = 0; i < 8; ++i) {
      int i2 = ci + di[i];
      int j2 = cj + dj[i];
      if (i2 >= 0 && i2 < h && j2 >= 0 && j2 < w && !cpy[i2][j2] &&
          !visited2[i2][j2]) {
        visited2[i2][j2] = true;
        q.push({i2, j2});
      }
    }
  }
}

// count white components in each shape
int count_comps() {
  int comps = 0;
  memset(visited2, false, sizeof(visited2));

  // sweep edges of board to check for components outside of shape
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && !cpy[i][j]) {
        bfs2(i, j);
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!visited2[i][j] && !cpy[i][j]) {
        bfs2(i, j);
        ++comps;
      }
    }
  }
  return comps;
}

int main() {
  h, w2;
  for (int ca = 1; GET(h) && GET(w2) && (h || w2); ++ca) {
    // input
    w = w2 * 4;
    int d;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w2; ++j) {
        scanf("%1x", &d);
        for (int k = 3; k >= 0; --k) {
          img[i][j * 4 + (3 - k)] = (d & (1 << k)) ? 1 : 0;
        }
      }
    }

    string res;

    // find each black connected component, isolate it in the cpy, and count
    // white components in that cpy - then based on the count, select a
    // character
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (img[i][j] && !visited[i][j]) {
          memset(cpy, false, sizeof(cpy));
          bfs(i, j);
          res.push_back(chars[count_comps()]);
        }
      }
    }

    sort(res.begin(), res.end());
    printf("Case %d: %s\n", ca, res.c_str());
  }
  return 0;
}
