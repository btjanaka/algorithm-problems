// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10050
// Title: Hartals
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=991
// Idea: Just simulate the hartals. May be a math solution but the problem is
// small enough to simulate.
// Difficulty: Easy
// Tags:
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  GET(t);

  int h[100];

  for(int test = 0; test < t; ++test) {
    int n;
    GET(n);

    int p;
    GET(p);

    for(int i = 0; i < p; ++i) {
      GET(h[i]);
    }

    int hartals = 0;

    for(int i = 1; i <= n; ++i) {
      if(i % 7 == 6 || i % 7 == 0) {
        continue;
      }

      for(int j = 0; j < p; ++j) {
        if(i % h[j] == 0) {
          ++hartals;
          break;
        }
      }
    }

    printf("%d\n", hartals);
  }

  return 0;
}
