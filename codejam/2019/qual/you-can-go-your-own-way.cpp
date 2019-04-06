// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) You Can Go Your Own Way
// Note: won't work for largest input
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

char buf[100101];

int n;

struct pair_hash {
  size_t operator()(const ii& p) const { return p.first * n + p.second; }
};

bool ok = false;
bool visited[1010][1010];
unordered_map<ii, ii, pair_hash> path;
void dfs(int r, int c, string& res) {
  if (visited[r][c]) return;
  visited[r][c] = true;

  if (r == n - 1 && c == n - 1) {
    ok = true;
    return;
  }

  if (r < n - 1 && path.find({r, c}) != path.end() &&
      path[{r, c}] == make_pair(r + 1, c)) {
    res.push_back('S');
    dfs(r + 1, c, res);
    if (!ok) res.pop_back();
  }
  if (ok) return;
  if (c < n - 1 && path.find({r, c}) != path.end() &&
      path[{r, c}] == make_pair(r, c + 1)) {
    res.push_back('E');
    dfs(r, c + 1, res);
    if (!ok) res.pop_back();
  }
}

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    GET(n);
    getchar();
    fgets(buf, 100100, stdin);

    // paths which are already taken
    path.clear();
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

    ok = false;
    memset(visited, false, sizeof(visited));
    string res;
    dfs(0, 0, res);
    printf("Case #%d: %s\n", caa, res.c_str());
  }
  return 0;
}
