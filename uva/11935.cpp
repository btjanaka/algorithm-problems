// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11935
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int event_d[60];  // Distance of each event
char events[60];  // F = fuel, L = leak, G = gas, M = mechanic, X = goal
int info[60];     // Mainly for fuel consumption
int event_i;      // Number of events

// Determine if we can make the journey with the given fuel capacity.
bool can(double cap) {
  double fuel = cap;
  int leaks = 0;
  int prev_d = 0;
  int curr_d = 0;
  double rate;
  for (int i = 0; i < event_i; ++i) {
    curr_d = event_d[i];
    fuel -= rate * (curr_d - prev_d);
    fuel -= leaks * (curr_d - prev_d);
    if (fuel < 0) return false;

    switch (events[i]) {
      case 'F':
        rate = (double)info[i] / 100;
        break;
      case 'L':
        ++leaks;
        break;
      case 'G':
        fuel = cap;
        break;
      case 'M':
        leaks = 0;
        break;
      case 'X':
        break;
    }
    prev_d = curr_d;
  }
  return fuel >= 0;
}

int main() {
  char buf[20];
  while (true) {
    // Get initial fuel consumption line
    GET(event_d[0]);
    events[0] = 'F';
    scanf("%*s %*s %d", &info[0]);
    if (info[0] == 0) break;  // Quit if this is the final line

    // Reset number of events
    event_i = 1;

    // Process other inputs
    while (true) {
      GET(event_d[event_i]);
      scanf("%s", buf);
      if (strcmp(buf, "Fuel") == 0) {
        events[event_i] = 'F';
        scanf("%*s %d", &info[event_i]);  // consumption
      } else if (strcmp(buf, "Leak") == 0) {
        events[event_i] = 'L';
      } else if (strcmp(buf, "Gas") == 0) {
        events[event_i] = 'G';
        scanf("%*s");  // station
      } else if (strcmp(buf, "Mechanic") == 0) {
        events[event_i] = 'M';
      } else if (strcmp(buf, "Goal") == 0) {
        events[event_i] = 'X';
        ++event_i;
        break;
      }
      ++event_i;
    }

    // Find answer
    double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
    while (fabs(hi - lo) > 1e-9) {
      mid = (lo + hi) / 2.0;
      if (can(mid)) {
        ans = mid;
        hi = mid;
      } else {
        lo = mid;
      }
    }
    printf("%.3lf\n", ans);
  }
  return 0;
}
