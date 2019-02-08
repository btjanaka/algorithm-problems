// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12100
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, m;
    GET(n);
    GET(m);
    queue<pair<int, bool>> jobs;
    priority_queue<int> pjobs;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      jobs.push({x, i == m});
      pjobs.push(x);
    }

    int res = 0;
    while (true) {
      if (jobs.front().first < pjobs.top()) {
        jobs.push(jobs.front());
        jobs.pop();
      } else {
        ++res;
        if (jobs.front().second) break;
        jobs.pop();
        pjobs.pop();
      }
    }

    printf("%d\n", res);
  }
  return 0;
}
