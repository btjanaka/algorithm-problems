// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) nastyhacks
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

int main() {
  int n;
  GET(n);
  while (n--) {
    int r, e, c;
    GET(r);
    GET(e);
    GET(c);
    if (e - c == r) {
      printf("does not matter\n");
    } else if (e - c < r) {
      printf("do not advertise\n");
    } else {
      printf("advertise\n");
    }
  }
  return 0;
}
