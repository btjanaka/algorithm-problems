// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) missinggnomes
// Title: Missing Gnomes
// Link: https://open.kattis.com/problems/missinggnomes
// Idea:
// Difficulty: easy
// Tags: greedy
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n, m;
  while (GET(n) > 0) {
    // input
    GET(m);
    queue<int> gqueue;
    unordered_set<int> gset;
    int g;
    for (int i = 0; i < m; ++i) {
      GET(g);
      gqueue.push(g);
      gset.insert(g);
    }

    // find remaining nums
    priority_queue<int, vector<int>, greater<int>> rem;
    for (int i = 1; i <= n; ++i) {
      if (gset.find(i) == gset.end()) {
        rem.push(i);
      }
    }

    // print results
    while (!(gqueue.empty() && rem.empty())) {
      if (rem.empty()) {
        printf("%d\n", gqueue.front());
        gqueue.pop();
      } else if (gqueue.empty()) {
        printf("%d\n", rem.top());
        rem.pop();
      } else if (gqueue.front() < rem.top()) {
        printf("%d\n", gqueue.front());
        gqueue.pop();
      } else {
        printf("%d\n", rem.top());
        rem.pop();
      }
    }
  }
  return 0;
}
