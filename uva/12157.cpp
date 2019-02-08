// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12157
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
  int t;
  GET(t);
  FORe(c, 1, t) {
    int n;
    GET(n);
    int mile = 0;
    int juice = 0;
    for (int i = 0; i < n; ++i) {
      int d;
      GET(d);
      mile += (d / 30 + 1) * 10;
      juice += (d / 60 + 1) * 15;
    }

    printf("Case %d: ", c);
    if (mile < juice) {
      printf("Mile %d\n", mile);
    } else if (juice < mile) {
      printf("Juice %d\n", juice);
    } else {
      printf("Mile Juice %d\n", mile);
    }
  }
  return 0;
}
