// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1203
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  // registrations
  char buf[30];
  unordered_map<int, int> ints;  // intervals
  // time, id
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  while (scanf("%s", buf) && strcmp(buf, "#") != 0) {
    int id, p;
    GET(id);
    GET(p);
    ints[id] = p;
    pq.push({p, id});
  }

  int k;
  GET(k);
  for (int i = 0; i < k; ++i) {
    printf("%d\n", pq.top().second);
    pq.push({pq.top().first + ints[pq.top().second], pq.top().second});
    pq.pop();
  }
  return 0;
}
