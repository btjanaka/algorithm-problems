// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeJam) 2017-1b-steed2-cruise-control
// Title: Steed 2: Cruise Control
// Link: https://code.google.com/codejam/contest/8294486/dashboard
// Idea: See comments.
// Difficulty: medium
// Tags: math
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Theory: Simply find the time t_max that it takes for any horse to get to the
// end. Then the max speed you can go is d / t_max, as you will reach the end at
// the same time as that slow horse.

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    int d, n;
    GET(d);
    GET(n);
    vector<ii> h(n);
    for (int i = 0; i < n; ++i) {
      GET(h[i].first);   // k
      GET(h[i].second);  // s
    }

    // sort the horses by distance from the end
    sort(h.begin(), h.end());

    // find the max time to get to the end
    double t_max = 0.0;
    for (int i = n - 1; i >= 0; --i) {
      double t_i = double(d - h[i].first) / double(h[i].second);
      t_max = max(t_i, t_max);
    }

    double res = double(d) / t_max;

    printf("Case #%d: %lf\n", caa, res);
  }
  return 0;
}
