// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10107
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  // two heaps, balance the incoming numbers between them
  int n;
  priority_queue<int, vector<int>, less<int>> highest_first;
  priority_queue<int, vector<int>, greater<int>> lowest_first;
  while (GET(n) > 0) {
    if (highest_first.size() == lowest_first.size()) {
      if (highest_first.empty()) {
        highest_first.push(n);
      } else if (n >= highest_first.top()) {
        lowest_first.push(n);
        highest_first.push(lowest_first.top());
        lowest_first.pop();
      } else {
        highest_first.push(n);
      }
      printf("%d\n", highest_first.top());
    } else if (highest_first.size() > lowest_first.size()) {
      if (n >= highest_first.top()) {
        lowest_first.push(n);
      } else {
        highest_first.push(n);
        lowest_first.push(highest_first.top());
        highest_first.pop();
      }
      printf("%d\n", (highest_first.top() + lowest_first.top()) / 2);
    } else {
      if (n <= lowest_first.top()) {
        highest_first.push(n);
      } else {
        lowest_first.push(n);
        highest_first.push(lowest_first.top());
        lowest_first.pop();
      }
      printf("%d\n", (highest_first.top() + lowest_first.top()) / 2);
    }
  }
  return 0;
}
