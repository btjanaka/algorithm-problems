// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11683
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

int main() {
  int a, c;
  while (GET(a) && a != 0) {
    GET(c);
    int tot = 0;
    int prev;
    int block;
    FOR(i, 0, c) {
      GET(block);
      switch (i) {
        case 0:
          tot = a - block;
          break;
        default:
          // New cuts are only introduced when the current height is less than
          // the previous one.
          if (block < prev) {
            tot += prev - block;
          }
      }
      prev = block;
    }

    printf("%d\n", tot);
  }
  return 0;
}
