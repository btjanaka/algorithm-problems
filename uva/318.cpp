// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 318
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n, m;
  for (int ca = 1; GET(n) && GET(m) && (n || m); ++ca) {
    // input
    vector<vector<ii>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int a, b, l;
      GET(a);
      GET(b);
      GET(l);
      g[a].push_back({b, l});
      g[b].push_back({a, l});
    }

    // BFS
    int clock = 0;
    int last_dom = 0;
    vector<int> time_to(n + 1, -1);  // -1 = not visited at all, -2 = visited
    vector<int> final_time(n + 1, 0);
    time_to[1] = 0;
    int visited = 0;
    while (visited != n) {
      // find amount to tick the clock
      int dt = INT_MAX;
      for (int i = 1; i <= n; ++i) {
        if (time_to[i] >= 0) dt = min(dt, time_to[i]);
      }
      clock += dt;

      // subtract tick from each time_to
      for (int i = 1; i <= n; ++i) {
        if (time_to[i] >= 0) time_to[i] -= dt;
      }

      // find nodes that are now ready
      for (int i = 1; i <= n; ++i) {
        if (time_to[i] == 0) {
          ++visited;
          final_time[i] = clock;
          last_dom = i;
          for (const ii& x : g[i]) {
            if (time_to[x.first] == -1) {
              time_to[x.first] = x.second;
            } else {
              time_to[x.first] = min(time_to[x.first], x.second);
            }
          }
          time_to[i] = -2;
        }
      }
    }

    // find out if there is a split that lasts longer than the clock
    bool btwn = false;
    int btwnclock = 0, btwnclockrem = 0, last1 = 0, last2 = 0;
    for (int u = 1; u <= n; ++u) {
      for (const ii& v : g[u]) {
        if (abs(final_time[v.first] - final_time[u]) != v.second) {
          int mn = min(final_time[v.first], final_time[u]);
          int mx = max(final_time[v.first], final_time[u]);
          int thisclock = mx + (v.second - (mx - mn)) / 2;
          int thisclockrem = (v.second - (mx - mn)) % 2 == 0 ? 0 : 5;
          if (thisclock > btwnclock ||
              thisclock == btwnclock && thisclockrem > btwnclockrem) {
            btwnclock = thisclock;
            btwnclockrem = thisclockrem;
            last1 = u;
            last2 = v.first;
          }
        }
      }
    }
    if (btwnclock > clock || (btwnclock == clock && btwnclockrem == 5))
      btwn = true;

    // output
    printf("System #%d\n", ca);
    if (!btwn) {
      printf("The last domino falls after %d.0 seconds, at key domino %d.\n",
             clock, last_dom);
    } else {
      printf(
          "The last domino falls after %d.%d seconds, between key dominoes %d "
          "and %d.\n",
          btwnclock, btwnclockrem, last1, last2);
    }
    printf("\n");
  }
  return 0;
}
