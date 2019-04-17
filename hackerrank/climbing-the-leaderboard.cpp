// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) climbing-the-leaderboard
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int n, m, x;
  vector<ii> board;

  // input
  GET(n);
  for (int i = 0; i < n; ++i) {
    GET(x);
    x = -x;
    int rank;
    if (i == 0) {
      rank = 1;
    } else {
      if (x == board.back().first) {
        rank = board.back().second;
      } else {
        rank = board.back().second + 1;
      }
    }
    board.push_back({x, rank});
  }

  // output
  GET(m);
  int alice;
  for (int i = 0; i < m; ++i) {
    GET(alice);
    auto it =
        lower_bound(board.begin(), board.end(), make_pair(-alice, 100),
                    [](const ii& a, const ii& b) { return a.first < b.first; });
    if (it == board.end()) {
      printf("%d\n", board.back().second + 1);
    } else {
      printf("%d\n", it->second);
    }
  }

  return 0;
}
