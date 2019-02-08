// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 234
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

vector<int> calc_err(int len[10], int p, vector<int> align[5]) {
  vector<int> diff(5, 0);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < align[i].size(); ++j) {
      int t = align[i][j];
      int mn_diff = INT_MAX;
      int tot = 0;
      for (int k = 0; k < p; ++k) {
        tot += len[k];
        mn_diff = min(mn_diff, abs(tot - t));
      }
      diff[i] += mn_diff;
    }
  }
  return diff;
}

int main() {
  int p;
  int a;
  int len[10];
  int res[10];
  for (int ca = 1; GET(p) && p; ++ca) {
    vector<int> align[5];  // times for each importance

    // input
    for (int i = 0; i < p; ++i) GET(len[i]);
    GET(a);
    for (int i = 0; i < a; ++i) {
      int imp, t;
      GET(imp);
      GET(t);
      align[imp - 1].push_back(t);
    }

    // go through all permutations of the set of shows
    int err = 0;
    sort(len, len + p);
    vector<int> diff = calc_err(len, p, align);
    memcpy(res, len, sizeof(int) * p);
    while (next_permutation(len, len + p)) {
      vector<int> curr_diff = calc_err(len, p, align);
      if (curr_diff < diff) {
        diff = curr_diff;
        memcpy(res, len, sizeof(int) * p);
      }
    }

    // output
    printf("Data set %d\n", ca);
    printf("  Order:");
    for (int i = 0; i < p; ++i) printf(" %d", res[i]);
    printf("\n");
    printf("  Error: %d\n", accumulate(diff.begin(), diff.end(), 0));
  }
  return 0;
}
