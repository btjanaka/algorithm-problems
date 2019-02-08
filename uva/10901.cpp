// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10901
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// 0: arrival time
// 1: whether the car is left or right (false for left, true for right)
// 2: final time of the car
int cars[10010][3];

int main() {
  int ca;
  GET(ca);
  bool first = true;
  while (ca--) {
    // input
    int n, t, m;
    GET(n);
    GET(t);
    GET(m);
    char dir[10];

    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d %s", &x, dir);
      cars[i][0] = x;
      cars[i][1] = strcmp(dir, "right") == 0;
    }

    // simulation
    queue<int> left, right;
    bool pos = false;  // false = left, true = right
    bool car_pos;
    int clock = 0;
    int cur_car = 0;
    while (!(cur_car == m && left.empty() && right.empty())) {
      // Push on any cars that arrived while the ferry was doing something else
      while (cur_car < m && cars[cur_car][0] <= clock) {
        if (cars[cur_car][1]) {
          right.push(cur_car);
        } else {
          left.push(cur_car);
        }
        ++cur_car;
      }

      // Just wait if both sides empty
      if (left.empty() && right.empty()) {
        clock = cars[cur_car][0];
        continue;
      }

      // Make ferry move
      if (!pos) {
        if (!left.empty()) {
          for (int i = 0; i < n && !left.empty(); ++i) {
            cars[left.front()][2] = clock + t;
            left.pop();
          }
          clock += t;
          pos = true;
        } else if (!right.empty()) {
          clock += t;
          pos = true;
        }
      } else {
        if (!right.empty()) {
          for (int i = 0; i < n && !right.empty(); ++i) {
            cars[right.front()][2] = clock + t;
            right.pop();
          }
          clock += t;
          pos = false;
        } else if (!left.empty()) {
          clock += t;
          pos = false;
        };
      }
    }

    // output
    if (first) {
      first = false;
    } else {
      putchar('\n');
    }
    for (int i = 0; i < m; ++i) {
      printf("%d\n", cars[i][2]);
    }
  }
  return 0;
}
