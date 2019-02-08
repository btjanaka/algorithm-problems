// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 978
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int ca;
  GET(ca);
  bool first = true;
  while (ca--) {
    priority_queue<int> green, blue;
    int b, sg, sb;
    scanf("%d %d %d", &b, &sg, &sb);
    for (int i = 0; i < sg; ++i) {
      int x;
      GET(x);
      green.push(x);
    }
    for (int i = 0; i < sb; ++i) {
      int x;
      GET(x);
      blue.push(x);
    }

    // green, blue
    int bats[b][2];
    while (!green.empty() && !blue.empty()) {
      int c;
      for (c = 0; c < b; ++c) {
        if (green.empty() || blue.empty()) break;
        bats[c][0] = green.top();
        bats[c][1] = blue.top();
        green.pop();
        blue.pop();
      }
      for (int i = 0; i < c; ++i) {
        if (bats[i][0] > bats[i][1]) {
          green.push(bats[i][0] - bats[i][1]);
        } else if (bats[i][0] < bats[i][1]) {
          blue.push(bats[i][1] - bats[i][0]);
        }
      }
    }

    // output
    if (first)
      first = false;
    else
      printf("\n");

    if (green.empty() && blue.empty()) {
      printf("green and blue died\n");
    } else if (blue.empty()) {
      printf("green wins\n");
      while (!green.empty()) {
        printf("%d\n", green.top());
        green.pop();
      }
    } else if (green.empty()) {
      printf("blue wins\n");
      while (!blue.empty()) {
        printf("%d\n", blue.top());
        blue.pop();
      }
    }
  }
  return 0;
}
