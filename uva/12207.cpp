// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12207
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int p, c;
  for (int ca = 1; GET(p) && GET(c) && !(!p && !c); ++ca) {
    printf("Case %d:\n", ca);
    char cmd;
    if (p <= c) {
      // Keep track of all positions if p is small enough
      list<int> used;
      vector<list<int>::iterator> pos(1, used.end());
      for (int i = 1; i <= p; ++i) {
        used.push_back(i);
        pos.push_back(--used.end());
      }
      for (int i = 0; i < c; ++i) {
        scanf(" %c", &cmd);
        int x;
        if (cmd == 'E') {
          GET(x);
          used.push_front(x);
          used.erase(pos[x]);
          pos[x] = used.begin();
        } else {
          printf("%d\n", used.front());
          used.push_back(used.front());
          pos[used.front()] = --used.end();
          used.pop_front();
        }
      }
    } else {
      // Otherwise we know we only go through population at most once
      unordered_set<int> used;
      list<int> expedite;
      unordered_map<int, list<int>::iterator> exp_pos;
      int cur = 1;
      for (int i = 0; i < c; ++i) {
        scanf(" %c", &cmd);
        int x;
        if (cmd == 'E') {
          GET(x);
          expedite.push_front(x);
          // Careful about checking whether this person is already set to be
          // expedited.
          if (exp_pos.find(x) == exp_pos.end()) {
            exp_pos[x] = expedite.begin();
          } else {
            expedite.erase(exp_pos[x]);
            exp_pos[x] = expedite.begin();
          }
        } else {
          if (expedite.empty()) {
            while (used.find(cur) != used.end()) ++cur;
            printf("%d\n", cur);
            used.insert(cur);
          } else {
            printf("%d\n", expedite.front());
            used.insert(expedite.front());
            exp_pos.erase(expedite.front());
            expedite.pop_front();
          }
        }
      }
    }
  }
  return 0;
}
