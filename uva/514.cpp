// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 514
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  stack<int> trains;
  int n;
  while (GET(n) && n) {
    int t;
    while (GET(t) && t) {
      while (!trains.empty()) trains.pop();
      int in = 1;
      for (int i = 1; i <= n; ++i) {
        if (i != 1) GET(t);

        if (in == t) {
          ++in;
        } else if (!trains.empty() && t == trains.top()) {
          trains.pop();
        } else {
          while (in <= n && in != t) {
            trains.push(in);
            ++in;
          }
          ++in;
        }
      }

      printf("%s\n", trains.empty() ? "Yes" : "No");
    }
    printf("\n");
  }
  return 0;
}
