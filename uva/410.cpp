// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 410
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

int spec[10];

int main() {
  int c, s;
  for (int ca = 1; scanf("%d %d", &c, &s) > 0; ++ca) {
    double avg = 0;
    FOR(i, 0, 2 * c) {
      if (i >= s) {
        spec[i] = 0;
      } else {
        GET(spec[i]);
        avg += spec[i];
      }
    }
    avg /= c;

    sort(spec, spec + 2 * c);

    printf("Set #%d\n", ca);
    double imb = 0;
    FOR(i, 0, c) {
      printf("%2d:", i);
      imb += abs((double)(spec[i] + spec[2 * c - i - 1]) - avg);
      if (spec[i] != 0) printf(" %d", spec[i]);
      if (spec[2 * c - i - 1] != 0) printf(" %d", spec[2 * c - i - 1]);
      PLN;
    }
    printf("IMBALANCE = %.5lf\n", imb);
    PLN;
  }
  return 0;
}
