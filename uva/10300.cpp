// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10300
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
  int n;
  GET(n);
  while (n--) {
    int f;
    GET(f);
    int size, animals, fness;
    long long tot = 0;
    for (int i = 0; i < f; ++i) {
      scanf("%d %d %d", &size, &animals, &fness);
      tot += size * fness;
    }
    printf("%lld\n", tot);
  }
  return 0;
}
