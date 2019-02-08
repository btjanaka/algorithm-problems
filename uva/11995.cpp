// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11995
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  while (GET(n) > 0) {
    int cmd, x;
    bool s_ok = true, q_ok = true, pq_ok = true;
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
      GET(cmd);
      GET(x);
      if (cmd == 1) {
        if (s_ok) s.push(x);
        if (q_ok) q.push(x);
        if (pq_ok) pq.push(x);
      } else {
        if (s_ok) {
          if (!s.empty() && s.top() == x) {
            s.pop();
          } else {
            s_ok = false;
          }
        }
        if (q_ok) {
          if (!q.empty() && q.front() == x) {
            q.pop();
          } else {
            q_ok = false;
          }
        }
        if (pq_ok) {
          if (!pq.empty() && pq.top() == x) {
            pq.pop();
          } else {
            pq_ok = false;
          }
        }
      }
    }

    int tot = s_ok + q_ok + pq_ok;
    if (tot > 1) {
      printf("not sure\n");
    } else if (tot == 0) {
      printf("impossible\n");
    } else if (s_ok) {
      printf("stack\n");
    } else if (q_ok) {
      printf("queue\n");
    } else if (pq_ok) {
      printf("priority queue\n");
    }
  }
  return 0;
}
