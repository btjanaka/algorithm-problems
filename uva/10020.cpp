// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10020
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

// left, right
pair<int, int> lines[100100];
pair<int, int> res[100100];
int num_lines;

int main() {
  int t;
  GET(t);
  while (t--) {
    // Input
    int m;
    GET(m);

    num_lines = 0;
    int l, r;
    while (scanf("%d %d", &l, &r) && !(!l && !r)) {
      lines[num_lines].first = l;
      lines[num_lines].second = r;
      ++num_lines;
    }

    // Sort by left and then right endpoint
    sort(lines, lines + num_lines);
    // for (int i = 0; i < num_lines; ++i)
    //   printf("%d %d\n", lines[i].first, lines[i].second);

    // Greedily go through searching for the next segment that takes us as far
    // right as possible.
    int pos = 0;
    int lines_i = 0;
    int res_i = 0;
    bool ok = true;
    while (pos < m) {
      // Search for next segment
      int max_l = -1;
      int max_r = -1;
      for (; lines_i < num_lines && lines[lines_i].first <= pos; ++lines_i) {
        if (lines[lines_i].second > max_r) {
          max_l = lines[lines_i].first;
          max_r = lines[lines_i].second;
        }
      }
      pos = max_r;  // Advance position

      // Record solution
      res[res_i].first = max_l;
      res[res_i].second = max_r;
      ++res_i;

      // Couldn't find a line segment, so no solution
      if (max_r == -1) {
        ok = false;
        break;
      }
    }

    // Print results
    if (ok) {
      printf("%d\n", res_i);
      FOR(i, 0, res_i) { printf("%d %d\n", res[i].first, res[i].second); }
    } else {
      printf("0\n");
    }
    if (t) PLN;
  }
  return 0;
}
