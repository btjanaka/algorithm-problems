// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11701
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
  double x;
  char num[100];
  while (scanf("%lf", &x) > 0) {
    memset(num, 0, sizeof(num));

    bool is_cantor = true;
    if (x == 1 || x == 0) {
      is_cantor = true;
    } else {
      // Convert the decimal to base 3, and if we see a 1 along the way, the
      // number is not cantor
      for (int i = 0; i < 20; ++i) {
        x *= 3;
        int whole = (int)x;
        x -= whole;
        if (whole == 1) {
          is_cantor = false;
          break;
        }
      }
    }

    printf(is_cantor ? "MEMBER\n" : "NON-MEMBER\n");
  }
  return 0;
}
