// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10656
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

// Remember it is sub-sequence, so all we need to do is filter out the positive
// numbers and print them!

int main() {
  int n;
  while (GET(n) && n) {
    bool has_pos = false;
    bool first = true;
    int x;
    FOR(i, 0, n) {
      GET(x);
      if (x > 0) {
        has_pos = true;
        if (first) {
          printf("%d", x);
          first = false;
        } else {
          printf(" %d", x);
        }
      }
    }
    if (!has_pos) printf("0");
    PLN;
  }
  return 0;
}
