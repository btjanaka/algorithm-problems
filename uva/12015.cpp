// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12015
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d\n", arr[_i]);                  \
      }                                           \
    }                                             \
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

char sites[10][110];
int relevance[10];

int main() {
  int t;
  GET(t);
  FORe(c, 1, t) {
    // Input
    FOR(i, 0, 10) {
      scanf("%s", sites[i]);
      scanf("%d", &relevance[i]);
    }

    // Find maximum score
    int mx = 0;
    FOR(i, 0, 10) {
      if (relevance[i] > mx) mx = relevance[i];
    }

    // Output
    printf("Case #%d:\n", c);
    FOR(i, 0, 10) {
      if (relevance[i] == mx) printf("%s\n", sites[i]);
    }
  }
  return 0;
}
