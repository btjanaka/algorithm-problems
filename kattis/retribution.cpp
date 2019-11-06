// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) retribution
// Title: Retribution
// Link: https://open.kattis.com/problems/retribution
// Idea: Implement the algorithm described. O(n^3) is fine in C++. There's also
// a pretty large time limit.
// Difficulty: medium
// Tags: implementation
#include <bits/stdc++.h>

using namespace std;

using dd = pair<double, double>;

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<dd> jud, tar, fea;

  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    jud.push_back({x, y});
  }
  for (int i = 0; i < m; ++i) {
    double x, y;
    cin >> x >> y;
    tar.push_back({x, y});
  }
  for (int i = 0; i < p; ++i) {
    double x, y;
    cin >> x >> y;
    fea.push_back({x, y});
  }

  vector<bool> used_j(n, false), used_t(m, false), used_f(p, false);

  double tot = 0.0;

  // find closest judge and tar
  for (int i = 0; i < n; ++i) {
    double mn_dist = 1e9;
    double mn_jud = 0;
    double mn_tar = 0;

    for (int j = 0; j < n; ++j) {
      if (used_j[j]) continue;

      for (int k = 0; k < m; ++k) {
        if (used_t[k]) continue;

        double dx = tar[k].first - jud[j].first;
        double dy = tar[k].second - jud[j].second;
        double dist = (dx * dx) + (dy * dy);
        if (dist < mn_dist) {
          mn_dist = dist;
          mn_jud = j;
          mn_tar = k;
        }
      }
    }

    tot += sqrt(mn_dist);
    used_j[mn_jud] = true;
    used_t[mn_tar] = true;
  }

  // reset judges
  used_j.assign(n, false);

  // find closest judge and feather
  for (int i = 0; i < n; ++i) {
    double mn_dist = 1e9;
    double mn_jud = 0;
    double mn_fea = 0;

    for (int j = 0; j < n; ++j) {
      if (used_j[j]) continue;

      for (int k = 0; k < p; ++k) {
        if (used_f[k]) continue;

        double dx = fea[k].first - jud[j].first;
        double dy = fea[k].second - jud[j].second;
        double dist = (dx * dx) + (dy * dy);
        if (dist < mn_dist) {
          mn_dist = dist;
          mn_jud = j;
          mn_fea = k;
        }
      }
    }

    tot += sqrt(mn_dist);
    used_j[mn_jud] = true;
    used_f[mn_fea] = true;
  }

  printf("%.6lf\n", tot);

  return 0;
}
