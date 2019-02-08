// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10954
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  while (GET(n) && n) {
    long long tot = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      pq.push(x);
    }

    while (pq.size() != 1) {
      int x1 = pq.top();
      pq.pop();
      int x2 = pq.top();
      pq.pop();
      pq.push(x1 + x2);
      tot += x1 + x2;
    }

    printf("%lld\n", tot);
  }
  return 0;
}
