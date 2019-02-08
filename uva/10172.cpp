// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10172
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    // Input
    int n, s, q;
    scanf("%d %d %d", &n, &s, &q);
    vector<queue<int>> stations(n, queue<int>());
    for (int i = 0; i < n; ++i) {
      int qi;
      GET(qi);
      for (int j = 0; j < qi; ++j) {
        int x;
        GET(x);
        --x;
        stations[i].push(x);
      }
    }

    // Simulation
    int tot = 0;
    int pos = 0;
    int empty = count_if(stations.begin(), stations.end(),
                         [](queue<int>& q) { return q.empty(); });
    stack<int> carrier;
    while (true) {
      bool prev_empty = stations[pos].empty();
      if (empty == n && carrier.empty()) break;

      // Unload cargo
      while (true) {
        if (carrier.empty()) {
          break;
        }
        if (carrier.top() == pos) {
          carrier.pop();
          ++tot;
        } else {
          if (stations[pos].size() < q) {
            stations[pos].push(carrier.top());
            carrier.pop();
            ++tot;
          } else {
            break;
          }
        }
      }

      // Load cargo
      while (!stations[pos].empty() && carrier.size() < s) {
        carrier.push(stations[pos].front());
        stations[pos].pop();
        ++tot;
      }

      // Keep track of number of empty stations
      if (prev_empty && !stations[pos].empty()) --empty;
      if (!prev_empty && stations[pos].empty()) ++empty;

      if (empty == n && carrier.empty()) break;

      // Go to next pos
      tot += 2;
      pos = (pos + 1) % n;
    }

    // Output
    printf("%d\n", tot);
  }
  return 0;
}
