// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) aboveaverage
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
typedef long long ll;
using namespace std;

double scores[1010];

int main() {
  int c;
  GET(c);
  while (c--) {
    int n;
    GET(n);
    double avg = 0;
    FOR(i, 0, n) {
      scanf("%lf", &scores[i]);
      avg += scores[i];
    }
    avg /= (double)n;
    int above = 0;
    FOR(i, 0, n) {
      if (scores[i] > avg) ++above;
    }
    printf("%.3lf%%\n", (double)above / n * 100.0);
  }
  return 0;
}
